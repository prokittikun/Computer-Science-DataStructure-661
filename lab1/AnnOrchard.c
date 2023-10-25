#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int orchard[n][n];
    int max = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            scanf("%d", &orchard[row][col]);
        }
    }
    int sum = 0;
    for (int colStart = 0; colStart <= n; colStart++)
    {
        for (int rowStart = 0; rowStart <= n; rowStart++)
        {
            for (int rowEnd = rowStart; rowEnd <= n; rowEnd++)
            {

                for (int colEnd = colStart; colEnd <= n; colEnd++)
                {
                    for (int i = rowStart; i < rowEnd; i++)
                    {
                        for (int j = colStart; j < colEnd; j++)
                        {
                            sum += orchard[i][j];
                            // printf("%d ", orchard[i][j]); DEBUG
                        }
                        if (sum > max)
                        {
                            max = sum;
                        }
                        // printf("sum is %d \n", sum); DEBUG
                    }
                    sum = 0;
                }
                // printf("\n"); DEBUG
            }
        }
    }
    printf("%d", max);
}