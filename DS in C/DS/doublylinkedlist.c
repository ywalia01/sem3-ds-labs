#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *GetNewNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(struct Node **head)
{
    int x;
    printf("Enter the element to be inserted: ");
    scanf("%d", &x);
    struct Node *temp = GetNewNode(x);
    if ((*head) == NULL)
    {
        (*head) = temp;
        return;
    }
    else
    {
        (*head)->prev = temp;
        temp->next = (*head);
        (*head) = temp;
    }
}

void InsertAtTail(struct Node **head)
{
    int x;
    printf("Enter the element to be inserted: ");
    scanf("%d", &x);
    struct Node *temp = GetNewNode(x);

    if ((*head) == NULL)
    {
        (*head) = temp;
        return;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
    }
}

void Traverse(struct Node *head)
{
    int ch;
    struct Node *temp = head;
    struct Node *temp1 = head;
    printf("1. Forward\t2. Reverse ");
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("Forward: ");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    else if (ch == 2)
    {
        if (temp1 == NULL)
        {
            return;
        }
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        printf("Reverse: ");
        while (temp1 != NULL)
        {
            printf("%d ", temp1->data);
            temp1 = temp1->prev;
        }
        printf("\n");
    }
    else
    {
        printf("Error! Invalid");
    }
}
int main(void)
{
    struct Node *head = NULL;
    int ch;

    while (1)
    {
        printf("\n\n1.Insert at Head\n2.Insert at Tail\n3.Traversal\n4.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            InsertAtHead(&head);
            break;
        case 2:
            InsertAtTail(&head);
            break;
        case 3:
            Traverse(head);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nError! Invalid\n");
        }
    }
}