#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for holding date information
typedef struct {
    int day;
    int month;
    int year;
} Date;

// Structure for holding information for each item in the shop
typedef struct {
    int code;
    char name[100];
    float price;
    int stock;
    Date date_received;
    Date expiration_date;
} ShopItem;

// Structure for each node in the binary search tree
typedef struct bstnode {
    ShopItem item;
    struct bstnode *left;
    struct bstnode *right;
} BSTNode;

// Function to create a new node in the binary search tree
BSTNode* create_node(ShopItem item) {
    BSTNode* new_node = (BSTNode*) malloc(sizeof(BSTNode));
    new_node->item = item;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert an item into the binary search tree
BSTNode* insert(BSTNode* root, ShopItem item) {
    if (root == NULL) {
        return create_node(item);
    } else if (item.code < root->item.code) {
        root->left = insert(root->left, item);
    } else if (item.code > root->item.code) {
        root->right = insert(root->right, item);
    } else {
        // If the code already exists, update the item
        root->item = item;
    }
    return root;
}

// Function to find an item by its code in the binary search tree
BSTNode* find(BSTNode* root, int code) {
    if (root == NULL || root->item.code == code) {
        return root;
    } else if (code < root->item.code) {
        return find(root->left, code);
    } else {
        return find(root->right, code);
    }
}

// Function to perform an in-order traversal of the binary search tree
// and print the valid items in lexicographic order of their names
void print_in_order(BSTNode* root) {
    if (root != NULL) {
        print_in_order(root->left);
        // Check if the item is still valid
        Date current_date = {6, 5, 2023};  // Example current date
        if (memcmp(&current_date, &root->item.date_received, sizeof(Date)) >= 0 &&
            memcmp(&current_date, &root->item.expiration_date, sizeof(Date)) <= 0) {
            printf("%d: %s\n", root->item.code, root->item.name);
        }
        print_in_order(root->right);
    }
}

int main() {
    // Initialize the root of the binary search tree
    BSTNode* root = NULL;

    int option = 0;
    do {
        printf("Menu:\n");
        printf("1. Insert an item\n");
        printf("2. Find an item by code and update it\n");
        printf("3. List valid items in lexicographic order of their names\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                // Get input for a new item
                ShopItem item;
                printf("Enter item code: ");
                scanf("%d", &item.code);
                printf("Enter item name: ");
                scanf("%s", item.name);
                printf("Enter item price: ");
                            scanf("%f", &item.price);
            printf("Enter item stock: ");
            scanf("%d", &item.stock);
            printf("Enter date received (day month year): ");
            scanf("%d %d %d", &item.date_received.day, &item.date_received.month, &item.date_received.year);
            printf("Enter expiration date (day month year): ");
            scanf("%d %d %d", &item.expiration_date.day, &item.expiration_date.month, &item.expiration_date.year);

            // Insert the new item into the binary search tree
            root = insert(root, item);
            printf("Item inserted successfully!\n");
            break;
        }
        case 2: {
            // Get input for the code of the item to find
            int code;
            printf("Enter item code to find: ");
            scanf("%d", &code);

            // Find the item in the binary search tree
            BSTNode* node = find(root, code);
            if (node == NULL) {
                printf("Item not found!\n");
            } else {
                // Get input for updating the item
                ShopItem item;
                printf("Enter updated item name: ");
                scanf("%s", item.name);
                printf("Enter updated item price: ");
                scanf("%f", &item.price);
                printf("Enter updated item stock: ");
                scanf("%d", &item.stock);
                printf("Enter updated date received (day month year): ");
                scanf("%d %d %d", &item.date_received.day, &item.date_received.month, &item.date_received.year);
                printf("Enter updated expiration date (day month year): ");
                scanf("%d %d %d", &item.expiration_date.day, &item.expiration_date.month, &item.expiration_date.year);

                // Update the item in the binary search tree
                item.code = code;
                root = insert(root, item);
                printf("Item updated successfully!\n");
            }
            break;
        }
        case 3: {
            // Print the valid items in lexicographic order of their names
            printf("Valid items:\n");
            print_in_order(root);
            break;
        }
        case 4: {
            // Exit the program
            printf("Exiting...\n");
            break;
        }
        default: {
            // Invalid input
            printf("Invalid option! Please try again.\n");
            break;
        }
    }
} while (option != 4);

return 0;
}
