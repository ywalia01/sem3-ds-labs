#include <stdio.h>
#include <stdlib.h>

int S_Largest(int *a, int n)
{
    int largest, secondLargest;
    largest = a[0];
    secondLargest = a[0];
    for (int j = 1; j < n; j++)
    {
        if (a[j] > largest)
        {
            secondLargest = largest;
            largest = a[j];
        }

        else if (a[j] > secondLargest && a[j] != largest)
        {
            secondLargest = a[j];
        }
    }
    return secondLargest;
}

int S_Smallest(int *a, int n)
{
    int smallest, secondSmallest;
    smallest = a[0];
    secondSmallest = a[1];
    for (int i = 1; i < n; i++)
    {
        if (smallest > a[i])
        {
            secondSmallest = smallest;
            smallest = a[i];
        }

        else if (secondSmallest > a[i] && a[i] != smallest)
        {
            secondSmallest = a[i];
        }
    }

    return secondSmallest;
}
int main(void)
{
    int a[20], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nThe second largest element is: %d", S_Largest(a, n));
    printf("\nThe second smallest element is: %d\n", S_Smallest(a, n));
}
