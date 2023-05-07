#include <stdio.h>
#include <stdlib.h>
  
typedef struct {
    int *ar;
    int size;
    int top1, top2;
} twoStacks;
  
void init(twoStacks *ts, int n)
{
    ts->size = n;
    ts->ar = (int*) malloc(n * sizeof(int));
    ts->top1 = n / 2 + 1;
    ts->top2 = n / 2;
}

void push1(twoStacks *ts, int x)
{
    if (ts->top1 > 0) {
        ts->top1--;
        ts->ar[ts->top1] = x;
    }
    else {
        printf("Stack Overflow By element : %d\n", x);
        return;
    }
}
  
void push2(twoStacks *ts, int x)
{
    if (ts->top2 < ts->size - 1) {
        ts->top2++;
        ts->ar[ts->top2] = x;
    }
    else {
        printf("Stack Overflow By element : %d\n", x);
        return;
    }
}

int pop1(twoStacks *ts)
{
    if (ts->top1 <= ts->size / 2) {
        int x = ts->ar[ts->top1];
        ts->top1++;
        return x;
    }
    else {
        printf("Stack UnderFlow\n");
        exit(1);
    }
}

int pop2(twoStacks *ts)
{
    if (ts->top2 >= ts->size / 2 + 1) {
        int x = ts->ar[ts->top2];
        ts->top2--;
        return x;
    }
    else {
        printf("Stack UnderFlow\n");
        exit(1);
    }
}

int main()
{
    twoStacks ts;
    init(&ts, 5);
    push1(&ts, 5);
    push2(&ts, 10);
    push2(&ts, 16);
    push1(&ts, 13);
    push2(&ts, 6);
    printf("Popped element from stack1 is : %d\n", pop1(&ts));
    push2(&ts, 12);
    printf("\nPopped element from stack2 is : %d\n", pop2(&ts));
    return 0;
}
