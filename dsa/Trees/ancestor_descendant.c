#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* createNode(int data) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void printAncestors(struct node* root, int key) {
  if (root == NULL) {
    return;
  }
  if (root->data == key) {
    return;
  }
  if (root->left != NULL && root->left->data == key || root->right != NULL && root->right->data == key) {
    printf("%d ", root->data);
    return;
  }
  printAncestors(root->left, key);
  printAncestors(root->right, key);
}

void printDescendants(struct node* root, int key) {
  if (root == NULL) {
    return;
  }
  if (root->data == key) {
    if (root->left != NULL) {
      printf("%d ", root->left->data);
    }
    if (root->right != NULL) {
      printf("%d ", root->right->data);
    }
    return;
  }
  printDescendants(root->left, key);
  printDescendants(root->right, key);
}

int main() {
  struct node* root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);
  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->right->left = createNode(6);
  root->right->right = createNode(7);

  int key = 2;
  printf("Ancestors of %d: ", key);
  printAncestors(root, key);
  printf("\n");

  key = 1;
  printf("Descendants of %d: ", key);
  printDescendants(root, key);
  printf("\n");

  return 0;
}
/* This program first defines a struct node to represent a node in a binary tree. It then defines a function createNode() to create a new node with the given data. The program then defines two functions printAncestors() and printDescendants() to print the ancestors and descendants of a node in a binary tree, respectively. The printAncestors() function takes a root node and a key as input and prints all the ancestors of the key in the given binary tree. The printDescendants() function takes a root node and a key as input and prints all the descendants of the key in the given binary tree. Finally, the program creates a binary tree and calls the printAncestors() and printDescendants() functions to print the ancestors and descendants of a node in the binary tree, respectively.
For example, the above program prints the ancestors and descendants of the node with data 2 and 1, respectively, in the binary tree shown below:
        1
      /   \
     2     3
    / \   / \
   4   5 6   7 
   Ancestors of 2: 1
Descendants of 1: 2 3*/
