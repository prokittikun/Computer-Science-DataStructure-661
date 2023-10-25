#include <stdio.h>
#include <stdlib.h>
// My Code
int main()
{
    int n;
    int m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    int temp[n][m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
            temp[i][j] = matrix[i][j];
        }
    }
    int doTemp = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (doTemp)
            {
                temp[i + 1][j] = matrix[i + 1][temp[i][j] - 1];
            }
            else
            {
                temp[i + 1][j] = matrix[i + 1][matrix[i][j] - 1];
                doTemp = 1;
            }
        }
    }
    
    for (int j = 0; j < m; j++)
    {
        printf("%d ", temp[n-1][j]);
    }
}

/**
 * ChatGPT Refactor
 * #include <stdio.h>
#include <stdlib.h>

void readMatrix(int n, int m, int matrix[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void applyTransformation(int n, int m, int matrix[n][m], int temp[n][m]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int index = (i % 2 == 0) ? matrix[i][j] - 1 : temp[i][j] - 1;
            temp[i + 1][j] = matrix[i + 1][index];
        }
    }
}

void printLastRow(int n, int m, int temp[n][m]) {
    for (int j = 0; j < m; j++) {
        printf("%d ", temp[n - 1][j]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int matrix[n][m];
    int temp[n][m];

    readMatrix(n, m, matrix);

    // Initialize temp with the first row of the matrix
    for (int j = 0; j < m; j++) {
        temp[0][j] = matrix[0][j];
    }

    applyTransformation(n, m, matrix, temp);

    printLastRow(n, m, temp);

    return 0;
}

 *
*/