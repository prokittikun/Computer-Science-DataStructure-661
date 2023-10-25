#include <stdio.h>
#include <stdlib.h>

void move(int **matrix, int i, int j, int n, int k) // ต้องเช็ค บน ขวา ล่าง ซ้าย
{
    if (n == j && i == n || k == n * n)
    {
        return;
    }
    matrix[i][j] = k;
    if (i - 1 >= 0 && matrix[i - 1][j] == 0)
    {
        move(matrix, i - 1, j, n, k + 1);
    }
    else if (j + 1 < n && matrix[i][j + 1] == 0)
    {
        move(matrix, i, j + 1, n, k + 1);
    }
    else if (i + 1 < n && matrix[i + 1][j] == 0)
    {
        move(matrix, i + 1, j, n, k + 1);
    }
    else if (j - 1 < n && matrix[i][j - 1] == 0)
    {
        move(matrix, i, j - 1, n, k + 1);
    }
    else if (i - 1 >= 0 && matrix[i - 1][j] < k && matrix[i - 1][j] != 1)
    {
        // matrix[i][j] = 2;
        move(matrix, i - 1, j, n, k - 1);
    }
    else if (j + 1 < n && matrix[i][j + 1] < k && matrix[i][j + 1] != 1)
    {
        move(matrix, i, j + 1, n, k - 1);
    }
    else if (i + 1 < n && matrix[i + 1][j] < k && matrix[i + 1][j] != 1)
    {
        move(matrix, i + 1, j, n, k - 1);
    }
    else if (j - 1 < n && matrix[i][j - 1] < k && matrix[i][j - 1] != 1)
    {
        move(matrix, i, j - 1, n, k - 1);
    }
}

int **allocate(int **matrix, int n)
{
    matrix = (int **)malloc(sizeof(int *) * n); // allocate rows
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(sizeof(int) * n); // allocate cols
    }
    return matrix;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int **matrix;
    matrix = allocate(matrix, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    if (matrix[0][1] == 1 && matrix[1][0] == 1)
    {
        printf("NO");
        return 0;
    }
    move(matrix, 0, 0, n, 2);
    if (matrix[n - 1][n - 1] != 0)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}