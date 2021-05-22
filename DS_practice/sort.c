#include <stdlib.h>
#include <stdio.h>

int Selection(int arr[], int n);
void swap(int *xp, int *yp);

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int *Selection(int arr[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
    return arr;
}

int main(void)
{
    int i, ch, n, arr[30], *ptr;
    printf("Enter the size of the array: ");
    scanf("%d", n);
    printf("Enter the array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }
    while (1)
    {
        printf("\n\n1.Selection Sort\n9.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            ptr = Selection(arr, n);
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("\nError! Invalid choice\n");
        }
    }
}