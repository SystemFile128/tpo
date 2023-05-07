#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10
struct faculty {
char firstname[20];
char surname[20];
char department[20];
char designation[20];
int emp_id;
};
struct node {
struct faculty f;
struct node *next;
};
int hash(char *firstname, char *surname) {
int sum = 0;
for(int i = 0; i < strlen(firstname); i++) {
sum += firstname[i];
}
for(int i = 0; i < strlen(surname); i++) {
sum += surname[i];
}
return sum % SIZE;
}
void insert(struct node *hash_table[], struct faculty f) {
int key = hash(f.firstname, f.surname);
struct node *new_node = (struct node*)malloc(sizeof(struct node));
new_node->f = f;
new_node->next = NULL;
if(hash_table[key] == NULL) {
hash_table[key] = new_node;
}
else {
struct node *temp = hash_table[key];
while(temp->next != NULL) {
temp = temp->next;
}
temp->next = new_node;
}
}
void display(struct node *hash_table[]) {
int empty = 1;
for(int i = 0; i < SIZE; i++) {
if(hash_table[i] != NULL) {
empty = 0;
printf("Index %d: ", i);
struct node *temp = hash_table[i];
while(temp != NULL) {
printf("(%s %s, %s, %s, %d) -> ", temp->f.firstname, temp->f.surname,
temp->f.department, temp->f.designation, temp->f.emp_id);
temp = temp->next;
}
printf("NULL\n");
}
}
if(empty) {
printf("Hash Table is Empty.\n");
}
}
void search(struct node *hash_table[], char *firstname, char *surname) {
int key = hash(firstname, surname);
if(hash_table[key] != NULL) {
struct node *temp = hash_table[key];
while(temp != NULL) {
if(strcmp(temp->f.firstname, firstname) == 0 && strcmp(temp->f.surname,
surname) == 0) {
printf("Faculty Found:\n");
printf("Name: %s %s\nDepartment: %s\nDesignation: %s\nEmployee ID: %d \n", temp->f.firstname, temp->f.surname, temp->f.department, temp->f.designation,temp->f.emp_id);
}
temp = temp->next;
}
}
printf("Faculty Not Found.\n");
}
int main() {
struct node *hash_table[SIZE] = {NULL};
struct faculty f;
char firstname[20], surname[20];
int emp_id, choice;
printf("Menu:\n");
printf("1. Add Faculty\n");
printf("2. Search Faculty\n");
printf("3. Display Faculty Database\n");
printf("4. Exit\n");
do {
printf("Enter Choice: ");
scanf("%d", &choice);
switch(choice) {
case 1:
printf("Enter First Name: ");
scanf("%s", firstname);
printf("Enter Surname: ");
scanf("%s", surname);
printf("Enter Department: ");
scanf("%s", f.department);
printf("Enter Designation: ");
scanf("%s", f.designation);
printf("Enter Employee ID: ");
scanf("%d", &emp_id);
strcpy(f.firstname, firstname);
strcpy(f.surname, surname);
f.emp_id = emp_id;
insert(hash_table, f);
printf("Faculty Added Successfully.\n");
break;
case 2:
printf("Enter First Name: ");
scanf("%s", firstname);
printf("Enter Surname: ");
scanf("%s", surname);
search(hash_table, firstname, surname);
break;
case 3:
display(hash_table);
break;
case 4:
printf("Exiting...\n");
break;
default:
printf("Invalid Choice. Try Again.\n");
break;
}
} while(choice != 4);
return 0;
}