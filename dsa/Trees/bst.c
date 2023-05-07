#include <stdio.h>
#include <stdlib.h>

struct date
{
    int day;
    int month;
    int year;
};

struct date today;

struct product
{
    int uid;
    char name[25];
    int price;
    int stock;
    struct date received;
    struct date expiry;
    int flag;
    struct product *left, *right;
} *head, *prev, *curr, *temp;

struct product *stack[100];
int top = -1;

struct product *pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    else
    {
        printf("Stack Underflow!");
        return NULL;
    }
}

void push(struct product *ele)
{
    if (top == 100)
    {
        printf("Stack Overflow");
    }
    else
    {
        stack[++top] = ele;
        printf("%d\n", top);
    }
}

int stackempty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void swap(struct product *a, struct product *b)
{
    struct product *temp;
    temp->uid = a->uid;
    for (int i = 0; i < 25; i++)
    {
        temp->name[i] = a->name[i];
    }
    temp->price = a->price;
    temp->stock = a->stock;
    temp->received = a->received;
    temp->expiry = a->expiry;

    a->uid = b->uid;
    for (int i = 0; i < 25; i++)
    {
        a->name[i] = b->name[i];
    }
    a->price = b->price;
    a->stock = b->stock;
    a->received = b->received;
    a->expiry = b->expiry;

    b->uid = temp->uid;
    for (int i = 0; i < 25; i++)
    {
        b->name[i] = temp->name[i];
    }
    b->price = temp->price;
    b->stock = temp->stock;
    b->received = temp->received;
    b->expiry = temp->expiry;
}

struct product *getproductfromuser()
{
    struct product *newnode = (struct product *)malloc(sizeof(struct product));
    printf("Enter Product ID: ");
    scanf("%d", &newnode->uid);
    printf("Enter Product Name: ");
    scanf("%s", newnode->name);
    printf("Enter Product Price: ");
    scanf("%d", &newnode->price);
    printf("Enter Product Stock: ");
    scanf("%d", &newnode->stock);
    printf("Enter Product Received Date: ");
    scanf("%d %d %d", &newnode->received.day, &newnode->received.month, &newnode->received.year);
    printf("Enter Product Expiry Date: ");
    scanf("%d %d %d", &newnode->expiry.day, &newnode->expiry.month, &newnode->expiry.year);
    newnode->left = newnode->right = NULL;
    return newnode;
}

void printproduct(struct product *curr)
{
    printf("Product ID: %d\n", curr->uid);
    printf("Product Name: %s\n", &curr->name);
    printf("Product Price: %d\n", curr->price);
    printf("Product Stock: %d\n", curr->stock);
    printf("Received Date: %d-%d-%d\n", curr->received.day, curr->received.month, curr->received.year);
    printf("Expiry Date: %d-%d-%d\n", curr->expiry.day, curr->expiry.month, curr->expiry.year);
}

void insertproduct()
{
    struct product *newnode = getproductfromuser();
    prev = curr = head;
    while (curr != NULL)
    {
        if (newnode->uid < curr->uid)
        {
            prev = curr;
            curr = curr->left;
        }
        else if (newnode->uid > curr->uid)
        {
            prev = curr;
            curr = curr->right;
        }
        else
        {
            printf("Product already exist!\n");
            return;
        }
    }
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        if (newnode->uid < prev->uid)
        {
            prev->left = newnode;
        }
        else
        {
            prev->right = newnode;
        }
    }
    printf("Product inserted successfully!\n");
}

void deleteproduct(int uid)
{
    prev = curr = head;
    while (curr != NULL)
    {
        if (uid < curr->uid)
        {
            prev = curr;
            curr = curr->left;
        }
        else if (uid > curr->uid)
        {
            prev = curr;
            curr = curr->right;
        }
        else
        {
            if (curr->right == NULL && curr->left == NULL)
            {
                if (prev->left == curr)
                {
                    prev->left = NULL;
                }
                else
                {
                    prev->right = NULL;
                }
                free(curr);
            }
            else if (curr->right != NULL && curr->left == NULL)
            {
                prev->right = curr->right;
                free(curr);
            }
            else if (curr->right == NULL && curr->left != NULL)
            {
                prev->left = curr->left;
                free(curr);
            }
            else
            {
                struct product *child, *parent;
                child = curr->right;
                parent = curr;
                while (child->left != NULL)
                {
                    parent = child;
                    child = child->left;
                }
                swap(curr, child);
                deleteproduct(child->uid);
                break;
            }
        }
    }
}

void updateproduct(struct product *curr)
{
    printf("Update Product Name (%s) : ", curr->name);
    scanf("%s", curr->name);
    printf("Update Product Price (%dRs): ", curr->price);
    scanf("%d", &curr->price);
    printf("Update Product Stock (%d Qty): ", curr->stock);
    scanf("%d", &curr->stock);
}

void search()
{
    int uid, ch;
    printf("Enter Product ID to search: ");
    scanf("%d", &uid);

    curr = head;
    while (curr != NULL)
    {
        if (uid < curr->uid)
        {
            curr = curr->left;
        }
        else if (uid > curr->uid)
        {
            curr = curr->right;
        }
        else
        {
            printf("Product Found!\n");
            printproduct(curr);

            printf("Do you want to update (1): ");
            scanf("%d", &ch);
            if (ch == 1)
            {
                updateproduct(curr);
            }
            break;
        }
    }
}

void deleteexpiry()
{
    curr = head;
    while (1)
    {
        while (curr != NULL)
        {
            push(curr);
            curr = curr->left;
        }
        if (!stackempty())
        {
            if (stack[top]->flag == 1)
            {
                temp = pop();
                if (temp->expiry.year < today.year)
                {
                    deleteproduct(temp->uid);
                }
                else if (temp->expiry.month < today.month)
                {
                    deleteproduct(temp->uid);
                }
                else if (temp->expiry.day < today.day)
                {
                    deleteproduct(temp->uid);
                }
            }
            else
            {
                curr = stack[top]->right;
                stack[top]->flag = 1;
            }
        }
        else
        {
            break;
        }
    }
}

void inorder()
{
    curr = head;
    while (1)
    {
        while (curr != NULL)
        {
            push(curr);
            curr = curr->left;
        }
        if (!stackempty())
        {
            curr = pop();
            printproduct(curr);
            curr = curr->right;
        }
        else
        {
            break;
        }
    }
}

void preorder()
{
    curr = head;
    while (1)
    {
        while (curr != NULL)
        {
            printproduct(curr);
            if (curr->right != NULL)
            {
                push(curr->right);
            }
            curr = curr->left;
        }
        if (!stackempty())
        {
            curr = pop();
        }
        else
        {
            break;
        }
    }
}

void postorder()
{
    curr = head;
    while (1)
    {
        while (curr != NULL)
        {
            push(curr);
            curr = curr->left;
        }
        if (!stackempty())
        {
            if (stack[top]->flag == 1)
            {
                printproduct(pop());
            }
            else
            {
                curr = stack[top]->right;
                stack[top]->flag = 1;
            }
        }
        else
        {
            break;
        }
    }
}

int main()
{
    today.day = 18;
    today.month = 2;
    today.year = 2023;
    int ch;
    int uid;
    while (1)
    {
        printf("1. Insert\n2. Search\n3. Delete\n4. Delete All Expiry\n5. Inorder\n6. Preorder\n7. Postorder\nChoose Your Operation: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertproduct();
            break;
        case 2:
            search();
            break;
        case 3:
            printf("Enter Product ID to search: ");
            scanf("%d", &uid);
            deleteproduct(uid);
            break;
        case 4:
            deleteexpiry();
            break;
        case 5:
            inorder();
            break;
        case 6:
            preorder();
            break;
        case 7:
            postorder();
            break;
        default:
            break;
        }
    }
}