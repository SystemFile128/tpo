#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node* left;
    struct Node* right;
    int data;
};
struct Node* createNode(int data)
{
    struct Node* n = (struct Node*)malloc(sizeof(struct Node*));
    n->data = data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void Preorder(struct Node* root)
{
    struct Node* r = root;
    if(r!=NULL)
    {
        printf("%d ",r->data);
        Preorder(r->left);
        Preorder(r->right);
    }
}
void Postorder(struct Node* root)
{
    struct Node* r=root;
    if(r!=NULL)
    {
        Postorder(r->left);
        Postorder(r->right);
        printf("%d ",r->data);
    }
}
void Inorder(struct Node* root)
{
    struct Node* r=root;
    if(r!=NULL)
    {
        Inorder(r->left);
        printf("%d ",r->data);
        Inorder(r->right);
    }
}
static int ctr=0;
int count(struct Node* root)
{
    if(root!=NULL)
    {
        count(root->left);
        ctr++;
        count(root->right);
    }
    return ctr;

}
void mirror(struct Node* root)
{
    if(root!=NULL)
    {
        mirror(root->left);
        mirror(root->right);
        struct Node* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
int ht(struct Node* root)
{
    if(root==NULL)
    return 0;
    else
    {
        int leftht = ht(root->left);
        int rightht = ht(root->right);
        if(leftht>rightht)
        return leftht+1;
        else 
        return rightht+1;
    }
}
void printlevel(struct Node* root,int level)
{
    if(root==NULL)
    return;
    if(level==0)
    printf("%d, ",root->data);
    else
    {
        printlevel(root->left,level-1);
        printlevel(root->right,level-1);

    }
}
void levelordertraversal(struct Node* root)
{
    int height = ht(root);
    for(int i=0;i<height;i++)
    printlevel(root,i);
}
int main()
{
    struct Node* root = createNode(1);
    struct Node* leftch = createNode(6);
    struct Node* rightch = createNode(7);
    struct Node* leftch1 = createNode(8);
    struct Node* rightch1 = createNode(9);
    struct Node* rightleftch = createNode(10);
    root->left = leftch;
    root->right = rightch;
    leftch->left =leftch1;
    leftch->right = rightch1;
    rightch->left = rightleftch;
    Preorder(root);
    printf("\n");
    Postorder(root);
    printf("\n");
    Inorder(root);
    printf("\n");
    int ctr = count(root);
    printf("%d ",ctr);
    mirror(root);
    printf("\n Mirror preorder ");
    Preorder(root);
    int x = ht(root);
    printf("\n Height is %d",x);
    printf("\n Level Order traversal is ");
    levelordertraversal(root);
    return 0;
}