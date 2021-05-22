#include <stdlib.h>
#include <stdio.h>

void push(int *arr, int *top, int size)
{
    int value;
    if ((*top) == size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter the element to be pushed: ");
        scanf("%d", &value);
        (*top) += 1;
        arr[(*top)] = value;
    }
}

void Pop(int *top)
{
    if ((*top) == -1)
    {
        printf("Error, ");
    }
    else
    {
        (*top) -= 1;
    }
}

void traverse(int *arr, int *top)
{
    int i;
    if ((*top) == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("The stack is: ");
        for (int i = (*top); i >= 0; i--)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void Top(int *top)
{
    printf("Top is %d\n", *top);
}

int main(void)
{
    int *arr, ch, top = -1, size;
    printf("\nEnter the size of stack: ");
    scanf("%d", &size);
    arr = (int *)malloc(sizeof(int) * size);

    while (1)
    {
        printf("\n====Stack Operations====");
        printf("\n1. Push\n2. Pop\n3. Traverse\n4. Top\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push(arr, &top, size);
            traverse(arr, &top);
            break;
        case 2:
            Pop(&top);
            traverse(arr, &top);
            break;
        case 3:
            traverse(arr, &top);
            break;
        case 4:
            Top(&top);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Error! Invalid Choice");
        }
    }
}