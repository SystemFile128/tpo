#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }
    struct Node* current = root;
    while (1) {
        if (key < current->data) {
            if (current->left == NULL) {
                current->left = newNode(key);
                break;
            } else {
                current = current->left;
            }
        } else if (key > current->data) {
            if (current->right == NULL) {
                current->right = newNode(key);
                break;
            } else {
                current = current->right;
            }
        } else { 
            break;
        }
    }
    return root;
}

 struct Node* deleteNode(struct Node* root, int key) {
        if (root == NULL) {
            return root;
        }
        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == NULL) {
                struct Node* temp = root->right;
                free(root);
                return temp;
            } else if (root->right == NULL) {
                struct Node* temp = root->left;
                free(root);
                return temp;
            }
            struct Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

int height(struct Node* root){
    struct Node* temp;
    int height = 0;
    struct Node *stack[100];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        temp = stack[top--];
        if (temp->right != NULL) {
            stack[++top] = temp->right;
        }
        if (temp->left != NULL) {
            stack[++top] = temp->left;
        }
        if (top + 1 > height) {
            height = top + 1;
        }
    }

    return height;
}

int getMax(struct Node* root){
    struct Node *stack[100];
    int top = -1;
    int max = root->data;
    stack[++top] = root;
    while (top >= 0) {
        struct Node *temp = stack[top--];
        if (temp->data > max) {
            max = temp->data;
        }
        if (temp->right) {
            stack[++top] = temp->right;
        }
        if (temp->left) {
            stack[++top] = temp->left;
        }
    }
    return max;
}

void printLevelOrder(struct Node* root){
    struct Node* temp;
    struct Node* queue[100];
    int front = 0, rear = -1;

    queue[++rear] = root;

    while (front <= rear) {
        temp = queue[front++];
        printf("%d ", temp->data);

        if (temp->left) {
            queue[++rear] = temp->left;
        }

        if (temp->right) {
            queue[++rear] = temp->right;
        }
    }
}

void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while (current != NULL || top >= 0) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

void mirror(struct Node* root) {
    if (root == NULL) {
        return;
    }

    struct Node* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        struct Node* current = stack[top--];
        struct Node* temp = current->left;
        current->left = current->right;
        current->right = temp;

        if (current->left) {
            stack[++top] = current->left;
        }
        if (current->right) {
            stack[++top] = current->right;
        }
    }
    
    printf("Mirrored Tree: ");
    inorderTraversal(root);
    printf("\n");
}

int main()
{
    struct Node* root = NULL;
    int choice, value;
    while (1) { 
        printf("1. Insert a node\n2. Delete a node\n3. Print level-wise\n4. Create mirror image of tree\n5. Find the height of the tree\n6. Print the tree\n7. Max\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
            case 2:
                printf("Enter the value to be deleted: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 3:
                printLevelOrder(root);
                break;
            case 4:
                mirror(root);
                break;
            case 5:
                int h = height(root);
                printf("The height of the tree is: %d\n", h);
                break;
            case 6:
                inorderTraversal(root);
                printf("\n");
                break;
            case 7:
                int m = getMax(root);
                printf("The max element of the tree is: %d\n", m);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again\n");
        }
    }
    return 0;
}
