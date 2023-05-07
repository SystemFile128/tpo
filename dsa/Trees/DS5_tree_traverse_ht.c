#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

struct node {
    int data;
    struct node* left;
    struct node* right;
};

int countNodes(struct node* root);
int height(struct node* node);
void preorderTraversal(struct node* root);
void postorderTraversal(struct node* root);
struct node* createNode(int data);
struct node* insertNode(struct node* root, int data);

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insertNode(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    else if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void preorderTraversal(struct node* root) // root- left - right
 {
    if (root == NULL) {
        return;
    }
    struct node* stack[MAX_SIZE];
    int top = -1;
    stack[++top] = root;// incrementing value of top and append the root value in the stack
    while (top >= 0) {
        struct node* temp = stack[top--];
        printf("%d ", temp->data);
        if (temp->right) // pushing right node first so that it is popped second because of LIFO
         {
            stack[++top] = temp->right;
        }
        if (temp->left) {
            stack[++top] = temp->left;
        }
    }
}

void postorderTraversal(struct node* root)
 {
    if (root == NULL) {
        return;
    }
    struct node* stack1[MAX_SIZE];
    struct node* stack2[MAX_SIZE];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;
    while (top1 >= 0) {
        struct node* temp = stack1[top1--];
        stack2[++top2] = temp;
        if (temp->left) {
            stack1[++top1] = temp->left;
        }
        if (temp->right) {
            stack1[++top1] = temp->right;
        }
    }
    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
}

int countNodes(struct node* root)// inorder traversal for number of nodes
 {
    if (root == NULL) {
        return 0;
    }
    struct node* stack[MAX_SIZE];
    int top = -1;
    int count = 0;
    stack[++top] = root;
    while (top >= 0) {
        struct node* temp = stack[top--];
count++;
if (temp->right) {
stack[++top] = temp->right;
}
if (temp->left) {
stack[++top] = temp->left;
}
}
return count;
}

int height(struct node* node) {
if (node == NULL) {
return -1;
}
int leftHeight = height(node->left);
int rightHeight = height(node->right);
if (leftHeight > rightHeight) {
return leftHeight + 1;
}
else {
return rightHeight + 1;
}
}
int main() {
    struct node* root = NULL;
    int data, n, i;
    
    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &n);
    
    for (i=0; i<n; i++) {
        printf("Enter node data: ");
        scanf("%d", &data);
        root = insertNode(root, data);
    }
    
    printf("\nPreorder Traversal: ");
    preorderTraversal(root);
    
    printf("\nPostorder Traversal: ");
    postorderTraversal(root);
    
    printf("\nTotal number of nodes: %d", countNodes(root));
    
    printf("\nHeight of tree: %d", height(root));
    
    return 0;
}
// Sample input nodes = 9, 9,4,11,2,7,5,8,15,14, preorder = 9,4,2,7,5,8,11,15,14, postorder = 2,5,8,7,4,14,15,11,9