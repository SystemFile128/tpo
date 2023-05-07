#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct Node {
    int data;
    struct Node* next;
};

/* Insert node at the beginning of the list */
void insert(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Print the linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Sort the linked list using insertion sort */
void insertionSort(struct Node** head_ref) {
    struct Node* current = (*head_ref);
    struct Node* sorted = NULL;
    while (current != NULL) {
        struct Node* next = current->next;
        if (sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        }
        else {
            struct Node* temp = sorted;
            while (temp->next != NULL && temp->next->data < current->data) {
                temp = temp->next;
            }
            current->next = temp->next;
            temp->next = current;
        }
        current = next;
    }
    (*head_ref) = sorted;
}

/* Main function */
int main() {
    struct Node* head = NULL;
    insert(&head, 5);
    insert(&head, 20);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 30);
    printf("Linked list before sorting: \n");
    printList(head);
    insertionSort(&head);
    printf("Linked list after sorting: \n");
    printList(head);
    return 0;
}
