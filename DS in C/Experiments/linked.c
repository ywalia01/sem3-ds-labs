#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

void Insert(struct Node **head)
{
    int data, n, ch;
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp2 = (*head);

    printf("1.At the Start\t2.At the End\t3.Any Position\t4.Sorted Case Insertion ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        temp1->data = data;
        temp1->next = NULL;

        temp1->next = (*head);
        (*head) = temp1;
        break;

    case 2:
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        temp1->data = data;
        temp1->next = NULL;

        while (temp2->next != NULL)
        {
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
        break;

    case 3:
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        printf("Enter the position: ");
        scanf("%d", &n);

        temp1->data = data;
        temp1->next = NULL;
        if (n == 1 || (*head) == NULL)
        {
            temp1->next = (*head);
            (*head) = temp1;
            return;
        }
        else
        {
            for (int i = 0; i < n - 2; i++)
            {
                temp2 = temp2->next;
            }
            temp1->next = temp2->next;
            temp2->next = temp1;
        }
        break;

    case 4:
        printf("Enter the element to be inserted: ");
        scanf("%d", &data);
        temp1->data = data;
        temp1->next = NULL;

        if ((*head) == NULL || (*head)->data >= data)
        {
            temp1->next = (*head);
            (*head) = temp1;
            return;
        }

        while (temp2->next != NULL && temp2->next->data < data)
        {
            temp2 = temp2->next;
        }
        temp1->next = temp2->next;
        temp2->next = temp1;
        break;

    default:
        printf("Error! Invalid");
    }
}

void Traverse(struct Node *head)
{
    struct Node *temp = head;
    printf("The list is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void Count(struct Node *head)
{
    int sum;
    struct Node *temp = head;
    printf("No. of nodes: ");
    while (temp != NULL)
    {
        sum = sum + 1;
        temp = temp->next;
    }
    printf("%d\n", sum);
}

void Search(struct Node *head)
{
    int item, count = 1;
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("Error! List Empty");
    }
    else
    {
        printf("Enter the element to be searched: ");
        scanf("%d", &item);
        while (temp != NULL)
        {
            if (item == temp->data)
            {
                printf("The element is found at position: ");
                printf("%d", count);
            }
            count = count + 1;
            temp = temp->next;
        }
        printf("\n");
    }
}

void Delete(struct Node **head)
{
    int i, n, ch;
    struct Node *temp1 = (*head);
    struct Node *temp2 = (*head);
    printf("1.Element wise\t2.Position wise ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        printf("Enter the element to be deleted: ");
        scanf("%d", &n);
        if (n == temp1->data)
        {
            (*head) = temp1->next;
            free(temp1);
            return;
        }
        while (temp1 != NULL && temp1->data != n)
        {
            temp1 = temp1->next;
        }
        while (temp2 != NULL && temp2->next->data != n)
        {
            temp2 = temp2->next;
        }

        temp2->next->next = temp1->next->next;
        break;
    case 2:
        printf("Enter the position of the element to be deleted: ");
        scanf("%d", &n);
        if (n == 1)
        {
            (*head) = temp1->next;
            free(temp1);
            return;
        }
        for (i = 0; i < n - 2; i++)
        {
            temp1 = temp1->next;
        }
        struct Node *temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
        break;
    default:
        printf("Error! Invalid");
    }
}

int main(void)
{
    int ch;
    struct Node *head = NULL;

    while (1)
    {
        printf("\n\n1.Insertion\n2.Traversal\n3.Count\n4.Search\n5.Deletion\n6.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            Insert(&head);
            break;
        case 2:
            Traverse(head);
            break;
        case 3:
            Count(head);
            break;
        case 4:
            Search(head);
            break;
        case 5:
            Delete(&head);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nError! Invalid\n");
        }
    }
}