#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int n)
{
    int **matrix = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)calloc(n, sizeof(int));
    }
    return matrix;
}

void addEdge(int **matrix, int u, int v)
{
    matrix[u][v] = 1;
}

void printMatrix(int **matrix, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
}
int main()
{
    int n = 5;
    int **matrix = createMatrix(n);
    addEdge(matrix, 0, 1);
    addEdge(matrix, 0, 3);
    addEdge(matrix, 1, 2);
    addEdge(matrix, 1, 4);
    addEdge(matrix, 2, 1);
    addEdge(matrix, 2, 4);
    addEdge(matrix, 4, 3);
    printMatrix(matrix, n);
}