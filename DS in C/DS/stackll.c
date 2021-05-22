#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

void push(struct Node **top)
{
    int x;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the element to be pushed: ");
    scanf("%d", &x);
    temp->data = x;
    temp->link = (*top);
    (*top) = temp;
    printf("Sucess! %d has been pushed\n", x);
}

void pop(struct Node **top)
{
    struct Node *temp;
    if ((*top) == NULL)
    {
        return;
    }
    temp = (*top);
    (*top) = (*top)->link;
    free(temp);
    printf("Success! Element has been popped\n");
}

void traverse(struct Node **top)
{
    struct Node *temp = (*top);
    printf("Stack: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
}

int main(void)
{
    struct Node *top = NULL;
    int ch, *s, size;
    // printf("\nEnter the size of stack: ");
    // scanf("%d", &size);
    // struct Node *temp = (struct Node*)malloc(sizeof(struct Node) * size);

    while (1)
    {
        printf("\n=====Stack Operations=====");
        printf("\n\n1.Push\n2.Pop\n3.Traverse\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push(&top);
            break;
        case 2:
            pop(&top);
            break;
        case 3:
            traverse(&top);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nError! Invalid\n");
        }
    }
}