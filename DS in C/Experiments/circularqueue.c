#include <stdio.h>
#include <stdlib.h>

void insert(int *cq, int *rear, int *front, int item)
{
    if (((*front) == 0 && (*rear) == 10 - 1) || ((*front) == (*rear) + 1))
    {
        printf("Queue Overflow\n");
        return;
    }
    if ((*front) == -1)
    {
        (*front) = 0;
        (*rear) = 0;
    }
    else
    {
        if ((*rear) == 10 - 1)
            (*rear) = 0;
        else
            (*rear) = (*rear) + 1;
    }
    cq[*rear] = item;
}
void delete (int *cq, int *rear, int *front)
{
    if ((*front) == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Element deleted from queue is: %d\n", cq[*front]);
    if ((*front) == (*rear))
    {
        (*front) = -1;
        (*rear) = -1;
    }
    else
    {
        if ((*front) == 10 - 1)
            (*front) = 0;
        else
            (*front) = (*front) + 1;
    }
}
void display(int *cq, int *rear, int *front)
{
    int front_pos = (*front), rear_pos = (*rear);
    if ((*front) == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    if (front_pos <= rear_pos)
        while (front_pos <= rear_pos)
        {
            printf("%d ", cq[front_pos]);
            front_pos++;
        }
    else
    {
        while (front_pos <= 10 - 1)
        {
            printf("%d ", cq[front_pos]);
            front_pos++;
        }
        front_pos = 0;
        while (front_pos <= rear_pos)
        {
            printf("%d ", cq[front_pos]);
            front_pos++;
        }
    }
    printf("\n");
}

int main(void)
{
    int cq[10], front = -1, rear = -1;
    int choice, item;
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
            printf("Enter element to be inserted: ");
            scanf("%d", &item);
            insert(cq, &rear, &front, item);
            break;
        case 2:
            delete (cq, &rear, &front);
            break;
        case 3:
            display(cq, &rear, &front);
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
}
