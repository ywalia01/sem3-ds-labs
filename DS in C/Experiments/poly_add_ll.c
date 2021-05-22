#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int pow;
    struct Node *next;
};

void readPolynomial(struct Node **poly)
{
    int coeff, exp, cont;
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    (*poly) = temp;

    do
    {
        printf("\nCoefficient: ");
        scanf("%d", &coeff);
        printf("Exponent: ");
        scanf("%d", &exp);
        temp->coeff = coeff;
        temp->pow = exp;
        temp->next = NULL;
        printf("Have more terms?\n1 = YES\n0 = NO,\tInput: ");
        scanf("%d", &cont);
        if (cont == 1)
        {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->next = NULL;
        }
        else if (cont == 0)
        {
        }
        else
        {
            printf("Error! Invalid Input");
        }
    } while (cont == 1);
}

void displayPolynomial(struct Node *poly)
{
    printf("\nPolynomial expression is: ");
    while (poly != NULL)
    {
        printf("%dX^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
}

void displayResultant(struct Node *poly)
{
    printf("\n\nResultant polynomial after addition is: ");
    while (poly != NULL)
    {
        printf("%dX^%d", poly->coeff, poly->pow);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n\n");
}

void addPolynomials(struct Node **result, struct Node *first, struct Node *second)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->next = NULL;
    (*result) = temp;
    while (first && second)
    {
        if (first->pow > second->pow)
        {
            temp->coeff = first->coeff;
            temp->pow = first->pow;
            first = first->next;
        }
        else if (first->pow < second->pow)
        {
            temp->coeff = second->coeff;
            temp->pow = second->pow;
            second = second->next;
        }
        else
        {
            temp->coeff = first->coeff + second->coeff;
            temp->pow = first->pow;
            first = first->next;
            second = second->next;
        }

        if (first && second)
        {
            temp->next = (struct Node *)malloc(sizeof(struct Node));
            temp = temp->next;
            temp->next = NULL;
        }
    }
    while (first || second)
    {
        temp->next = (struct Node *)malloc(sizeof(struct Node));
        temp = temp->next;
        temp->next = NULL;

        if (first)
        {
            temp->coeff = first->coeff;
            temp->pow = first->pow;
            first = first->next;
        }

        else if (second)
        {
            temp->coeff = second->coeff;
            temp->pow = second->pow;
            second = second->next;
        }
    }
}

int main(void)
{

    struct Node *first = NULL;
    struct Node *second = NULL;
    struct Node *result = NULL;

    printf("\nEnter the corresponding data:\n");
    printf("\nFirst polynomial: ");
    readPolynomial(&first);
    displayPolynomial(first);
    printf("\n\nSecond polynomial: ");
    readPolynomial(&second);
    displayPolynomial(second);
    addPolynomials(&result, first, second);
    displayResultant(result);
}