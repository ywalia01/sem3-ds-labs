#include <stdio.h>
#include <stdlib.h>

void insert(int *q, int *rear, int *front)
{
    int item;
    if ((*rear) == 50 - 1)
        printf("Queue Overflow\n");
    else
    {
        if ((*front) == -1)
            (*front) = 0;
        printf("Enter element to be inserted: ");
        scanf("%d", &item);
        (*rear) = (*rear) + 1;
        q[*rear] = item;
    }
}
void delete (int *q, int *rear, int *front)
{
    if ((*front) == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    else
    {
        printf("Element deleted from queue: %d\n", q[*front]);
        (*front) = (*front) + 1;
    }
}
void display(int *q, int *rear, int *front)
{
    int i;
    if ((*front) == -1)
        printf("Queue is empty\n");
    else
    {
        printf("Queue is: ");
        for (i = (*front); i <= (*rear); i++)
        {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main(void)
{
    int q[50], rear = -1, front = -1;
    int choice;
    while (1)
    {
        printf("\n1.Insertion\n");
        printf("2.Deletion\n");
        printf("3.Traversal\n");
        printf("4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(q, &rear, &front);
            break;
        case 2:
            delete (q, &rear, &front);
            break;
        case 3:
            display(q, &rear, &front);
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
}
