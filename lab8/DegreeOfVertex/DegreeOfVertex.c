#include <stdio.h>
#include <stdlib.h>

typedef struct Node_
{
    int adj_vertex;
    struct Node_ *next;

} Node;

Node **createGraph(int n)
{
    Node **graph = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 0; i < n; i++)
    {
        graph[i] = NULL;
    }
    return graph;
}

void addEdge(Node **adjList, int u, int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->adj_vertex = v;
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = (Node *)malloc(sizeof(Node));
    newNode->adj_vertex = u;
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void printDegree(Node **adjList, int n, int k)
{
    int degree = 0;
    for (int i = 0; i < n; i++)
    {
        // printf("adj[%d]", i);
        while (adjList[i] != NULL)
        {
            // printf("->%d", adjList[i]->adj_vertex);
            if(adjList[i]->adj_vertex == k){
                // printf("(%d)", i);
                degree++;
            }
            adjList[i] = adjList[i]->next;
        }
        // printf("\n");
    }
    printf("%d", degree);
}
int main()
{
    int n = 0, m = 0, k = 0;
    scanf("%d %d", &n, &m);
    scanf("%d", &k);
    Node **graph = createGraph(n);
    for (int i = 0; i < m; i++)
    {
        int u = 0, v = 0;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }
    printDegree(graph, n, k);
}