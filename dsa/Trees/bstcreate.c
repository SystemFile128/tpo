#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* insertBST(struct Node* T, int data)
{
    if(T!=NULL)
    {
        if(data<T->data)
        T->left = insertBST(T->left,data);
        else
        T->right = insertBST(T->right,data);
    }
    else
    {
        T = (struct Node*)malloc(sizeof(struct Node*));
        T->data = data;
        T->left = NULL;
        T->right = NULL;
    }
    return T;// returning original root node
}
void Inorder(struct Node* root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}
struct Node* search(struct Node* root,int key)
{
    if(root==NULL)
    return NULL;
    if(root->data==key)
    return root;
    if(key<root->data)
    return search(root->left,key);
    else
    return search(root->right,key);
}
/*void insert(struct Node* root, struct Node* element)
{
    struct Node* prev = root;// hold the value of previous node to append the new node
    if(root->data==element->data)
    {
        printf("Element already present in BST ");
        return;
    }
    if(root->data)
}*/
void mirror(struct Node* root)
{
    if(root!=NULL)
    {
        struct Node* temp;
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
struct node *inOrderPredecessor(struct node* root)// deletion of node
{
    root = root->left;
    while (root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value)// deletion of the node
{

    struct node* iPre;
    if (root == NULL){
        return NULL;
    }
    if (root->left==NULL&&root->right==NULL){
        free(root);
        return NULL;
    }

    //searching for the node to be deleted
    if (value < root->data){
        root-> left = deleteNode(root->left,value);
    }
    else if (value > root->data){
        root-> right = deleteNode(root->right,value);
    }
    //deletion strategy when the node is found
    else{
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}
int main()
{
    struct Node* root = NULL;
    printf("Enter number of nodes ");
    int n;
    scanf("%d",&n);
    int data;
    for(int i=0;i<n;i++)
    {
        printf("Enter value for the node ");
        scanf("%d",&data);
        root = insertBST(root,data);
        
    }
    Inorder(root);
    //mirror(root);
    //printf("\n Mirror image inorder ");
    //Inorder(root);
    int element;
    printf("Enter element to insert ");
    scanf("%d",&element);
    struct Node* s = insertBST(root,element);
    printf("New inorder is \n ");
    Inorder(root);
     printf("Enter element to search ");
     int x;
    scanf("%d",&x);
    struct Node* q = search(root,x);
    if(q==NULL)
    printf("Element not found");
    else 
    printf("element found");
}

/* sample input and output
Enter number of nodes 5
Enter value for the node 5
Enter value for the node 3
Enter value for the node 6
Enter value for the node 1
Enter value for the node 4
Tree -             5
                 /   \
                3      6
               / \      
              1   4
Inorder - 1 3 4 5 6 
*/