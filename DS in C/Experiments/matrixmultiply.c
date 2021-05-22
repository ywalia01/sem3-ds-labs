#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int m, n, p, q, i, j, k, sum = 0;
    int first[10][10], second[10][10], multiply[10][10];

    printf("Enter no. of rows and columns for 1st matrix\n");
    scanf("%d%d", &m, &n);
    printf("Enter no. of rows and columns for 2nd matrix\n");
    scanf("%d%d", &p, &q);

    //Validation
    if (n != p)
        printf("Multiplication not possible\n");
    else
    {
        printf("Enter elements of 1st matrix\n");
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &first[i][j]);

        printf("Enter elements of 2nd matrix\n");
        for (i = 0; i < p; i++)
            for (j = 0; j < q; j++)
                scanf("%d", &second[i][j]);

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < q; j++)
            {
                for (k = 0; k < p; k++)
                {
                    sum = sum + first[i][k] * second[k][j];
                }

                multiply[i][j] = sum;
                sum = 0;
            }
        }

        printf("Product of the matrices:\n");

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < q; j++)
                printf("%d\t", multiply[i][j]);
            printf("\n");
        }
    }
}