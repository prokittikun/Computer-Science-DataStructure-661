#include <stdio.h>
#include <stdlib.h>

int **createGraph(int n)
{
    int **matrix = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)calloc(sizeof(int),n);
    }
    return matrix;
    
    
}

void addEdge(int **matrix, int u, int v){
    //undirected
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}

void printGraph(int **matrix, int n){
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
    int **matrix = createGraph(n);
    addEdge(matrix, 0,1);
    addEdge(matrix, 0,2);
    addEdge(matrix, 2,1);
    addEdge(matrix, 1,3);
    addEdge(matrix, 3,0);
    addEdge(matrix, 4,3);
    printGraph(matrix, n);
}