#include <stdio.h>
#include <stdlib.h>

typedef struct Node_
{
    int adj_vertex;
    int visited;
    struct Node_ *next;

} Node;

Node **createGraph(int n)
{
    Node **graph = (Node **)malloc(sizeof(Node *) * n);
    for (int i = 1; i <= n; i++)
    {
        graph[i] = (Node *)malloc(sizeof(Node));
        graph[i]->adj_vertex = i;
        graph[i]->visited = 0;
        graph[i]->next = NULL;
    }
    return graph;
}

void addEdge(Node **adjList, int u, int v)
{
    // adjList[v]->next = adjList[u]->next;
    // adjList[u]->next = adjList[v];

    // adjList[u]->next = adjList[v]->next;
    // adjList[v]->next = adjList[u];
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->adj_vertex = v;
    newNode->next = adjList[u]->next;
    newNode->visited = 0;
    adjList[u]->next = newNode;

    newNode = (Node *)malloc(sizeof(Node));
    newNode->adj_vertex = u;
    newNode->next = adjList[v]->next;
    newNode->visited = 0;
    adjList[v]->next = newNode;
}

void DFS(Node **graph, int vertex)
{
    graph[vertex]->visited = 1;
    Node *adjacentNode = graph[vertex]->next;
    while (adjacentNode != NULL)
    {
        int adjVertex = adjacentNode->adj_vertex;
        if (graph[adjVertex]->visited == 0)
        {
            DFS(graph, adjVertex);
        }
        adjacentNode = adjacentNode->next;
    }
}


void DFSInit(Node **graph, int n, int m)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (graph[i]->visited == 0)
        {
            count++;
            DFS(graph, i);
        }

    }
    printf("%d", (count-1));
    // for (int i = 1; i <= n; i++)
    // {
    //     while (graph[i] != NULL)
    //     {
    //         printf("%d->", graph[i]->adj_vertex);
    //         graph[i] = graph[i]->next;
    //     }

    //     printf("\n");
    // }
}
int main()
{
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    Node **graph = createGraph(n);
    for (int i = 0; i < m; i++)
    {
        int u = 0, v = 0;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    DFSInit(graph, n, m);
}