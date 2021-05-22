#include <stdio.h>
void bubble_sort(int *a, int *n)
{
    int i = 0, j = 0, temp;
    for (i = 0; i < *n; i++)
    {
        for (j = 0; j < *n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void traverse(int *a, int *n)
{
    for (int i = 0; i < *n; i++)
        printf("%d\n", a[i]);
}

void insert(int *a, int *n)
{
    int i, loc, item;
    printf("Enter the location for insertion: ");
    scanf("%d", &loc);
    loc--;
    //Validation
    if (loc < 0 || loc > *n)
    {
        printf("Error! Invalid location");
    }
    //Insertion of the item
    else
    {
        *n++;
        printf("\nEnter the element to be inserted : ");
        scanf("%d", &item);
        for (i = *n - 1; i >= loc; i--)
        {
            a[i + 1] = a[i];
        }
        a[loc] = item;
        // printf("\nThe new array is : \n");
        // for (i = 0; i < n; i++)
        // {
        //     printf("%d ", a[i]);
        // }
    }
}

int main()
{
    int a[100], n, i, d, swap;
    printf("Enter number of elements in the array:\n");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    bubble_sort(a, &n);
    printf("After Bubble Sort\n");
    traverse(a, &n);
    insert(a, &n);
    traverse(a, &n);
    return 0;
}