#include <stdio.h>
#include <stdlib.h>

void push(int *s, int *top, int size)
{
    int x;
    if ((*top) == size - 1)
    {
        printf("Error! Stack Overflow\n");
        return;
    }
    else
    {
        printf("Enter the element to be pushed: ");
        scanf("%d", &x);
        (*top)++;
        s[(*top)] = x;
        printf("Success! %d has been pushed\n", x);
    }
}

void pop(int *s, int *top)
{
    if ((*top) == -1)
    {
        printf("Error! Stack Underflow");
        return;
    }
    else
    {
        (*top)--;
        printf("Success! %d popped\n", s[(*top) + 1]);
    }
}

void topp(int *s, int *top)
{
    if ((*top) == -1)
    {
        printf("Stack Empty hence, Top is: %d\n", s[(*top)]);
    }
    else
    {
        printf("Top: %d\n", s[(*top)]);
    }
}

void traverse(int *s, int *top)
{
    int i;

    if ((*top) == -1)
    {
        printf("Stack: Such Empty!");
    }
    else
    {
        printf("Stack: ");
        for (i = 0; i <= (*top); i++)
        {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}

int main(void)
{
    int top = -1, ch, *s, size;
    printf("\nEnter the size of stack: ");
    scanf("%d", &size);
    s = (int *)malloc(sizeof(int) * size);

    while (1)
    {
        printf("\n=====Stack Operations=====");
        printf("\n\n1.Push\n2.Pop\n3.Top\n4.Traverse\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push(s, &top, size);
            break;
        case 2:
            pop(s, &top);
            break;
        case 3:
            topp(s, &top);
            break;
        case 4:
            traverse(s, &top);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nError! Invalid\n");
        }
    }
}