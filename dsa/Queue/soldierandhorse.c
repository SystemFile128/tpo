#include <stdio.h>
#include <stdlib.h>

struct node
{
    int soldier;
    struct node *next;
} *head;

void enqueue(int soldier)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->soldier = soldier;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        struct node *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = head;
    }
}

int lenqueue()
{
    int count = 0;
    struct node *p = head;
    do
    {
        count++;
        p = p->next;
    } while (p != head);
    return count;
}

void dequeue(struct node *soldier)
{
    struct node *p = head;
    while (p->next != soldier)
    {
        p = p->next;
    }
    p->next = soldier->next;
    free(soldier);
}

void findSoldierSeekingHelp(int x, int jump)
{
    struct node *p = head;
    struct node *temp;

    while (lenqueue() > 1)
    {
        while (p->soldier != x)
        {
            p = p->next;
        }
        for (int i = 0; i < jump; i++)
        {
            p = p->next;
        }
        x = p->next->soldier;
        temp = p->next;
        dequeue(p);
        p = temp;
    }
    printf("The soldier seeking help is %d", p->soldier);
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    int x = 3;
    int jump = 2;

    findSoldierSeekingHelp(x, jump);
}