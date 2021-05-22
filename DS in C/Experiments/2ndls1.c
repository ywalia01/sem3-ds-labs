#include <stdio.h>
#include <stdlib.h>
void bubblesort(int *a, int *n)
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
    printf("After bubble sort: ");
    for (i = 0; i < *n; i++)
        printf("%d ", a[i]);
}

int main(void)
{
    int a[20], n, i;
    printf("Enter the no. of elements: ");
    scanf("%d", &n);

    printf("\nEnter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    bubblesort(a, &n);
    printf("\n\nSecond smallest element: %d", a[1]);
    printf("\nSecond largest element: %d\n", a[n - 2]);
}
