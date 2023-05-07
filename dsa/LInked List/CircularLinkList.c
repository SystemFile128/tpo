// Write program to create a circular linked List
// and perform insertion and deletion operations

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *ptr;
} *last, *curr, *temp, *prev;

void create(int x)
{
    curr = malloc(sizeof(struct node));
    curr->data = x;
    if (last == NULL)
    {
        printf("\nCircular Linked List do not exist. Creating..");
        last = curr;
        curr->ptr = curr;
    }
    else
    {
        printf("\nCircular Linked List already exist. Inserting at the end..");
        curr->ptr = last->ptr;
        last->ptr = curr;
        last = curr;
    }
}

void display()
{
    if (last == NULL)
    {
        printf("\nCircular Linked List do not exist. Please Create first..");
    }
    else
    {
        curr = last->ptr;
        while (curr != last)
        {
            printf("| %d | %u |---->", curr->data, curr->ptr);
            curr = curr->ptr;
        }
        printf("| %d | %u |---->", curr->data, curr->ptr);
    }
}

int length()
{
    int length = 0;
    if (last == NULL)
    {
        return length;
    }
    else
    {
        curr = last->ptr;
        while (curr != last)
        {
            length++;
            curr = curr->ptr;
        }
        return length + 1;
    }
}

void insert_loc(int loc, int data)
{
    if (last == NULL)
    {
        create(data);
    }
    else
    {
        if (loc <= length())
        {
            temp = last;
            curr = malloc(sizeof(struct node));
            curr->data = data;
            for (int i = 1; i < loc; i++)
            {
                temp = temp->ptr;
            }
            curr->ptr = temp->ptr;
            temp->ptr = curr;
        }
        else
        {
            printf("\nLocation is way to big to insert!");
        }
    }
}

void insert_after_data(int loc, int data)
{
    if (last == NULL)
    {
        create(data);
    }
    else
    {
        temp = last;
        curr = malloc(sizeof(struct node));
        curr->data = data;
        while (temp->data != loc)
        {
            temp = temp->ptr;
        }
        curr->ptr = temp->ptr;
        temp->ptr = curr;
        if (temp == last)
        {
            last = curr;
        }
    }
}

void delete_loc(int loc)
{
    if (last == NULL)
    {
        printf("\nCircular Linked List do not exist. Please Create first..");
    }
    else
    {
        if (loc <= length())
        {
            curr = last;
            for (int i = 1; i < loc; i++)
            {
                curr = curr->ptr;
            }
            if (curr->ptr == last)
            {
                last = curr;
            }
            curr->ptr = curr->ptr->ptr;
            free(curr->ptr);
        }
        else
        {
            printf("\nLocation is way to big to delete!");
        }
    }
}

void delete(int data)
{
    if (last == NULL)
    {
        printf("\nCircular Linked List do not exist. Please Create first..");
    }
    else
    {
        temp = last->ptr;
        while (temp->data != data)
        {
            prev = temp;
            temp = temp->ptr;
        }
        if (data == last->ptr->data)
        {
            last->ptr = temp->ptr;
        }
        else
        {
            prev->ptr = temp->ptr;
        }
        free(temp);
    }
}

int main()
{
    int ch, loc, data;

    while (1)
    {
        printf("\n\n1. Create Circular Linked List\n2. Display Circular Lisked List\n3. Insert node at specific location\n4. Insert node after specific data node\n5. Delete node at specific location\n6. Delete specifc data node\n");
        printf("Enter desired operation: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter Data: ");
            scanf("%d", &data);
            create(data);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("\nEnter location to insert node: ");
            scanf("%d", &loc);
            printf("Enter data: ");
            scanf("%d", &data);
            insert_loc(loc, data);
            break;
        case 4:
            printf("\nEnter data of node after which new node is to be inserted: ");
            scanf("%d", &loc);
            printf("Enter data: ");
            scanf("%d", &data);
            insert_after_data(loc, data);
            break;
        case 5:
            printf("\nEnter location to delete node: ");
            scanf("%d", &loc);
            delete_loc(loc);
            break;
        case 6:
            printf("\nEnter data to detele node: ");
            scanf("%d", &data);
            delete (data);
        default:
            printf("Invalid Input");
        }
    }
}