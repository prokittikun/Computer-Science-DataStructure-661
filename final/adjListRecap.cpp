#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> Vector;

Vector *createAdjList(int n)
{
    return new vector<int>[n];
}

void addEdge(Vector *adjList, int u, int v)
{
    // undirected
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void removeEdge(Vector *adjList, int u, int v)
{
    for (int i = 0; i < adjList[u].size(); i++)
    {
        if (adjList[u].at(i) == v)
        {
            adjList[u].erase(adjList[u].begin() + i);
        }
    }
    for (int i = 0; i < adjList[v].size(); i++)
    {
        if (adjList[v].at(i) == u)
        {
            adjList[v].erase(adjList[v].begin() + i);
        }
    }
}

void printAdjList(Vector *adjList, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "[" << i << "]"
             << "head ->";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i].at(j) << "->";
        }
        cout << "NULL\n";
    }
}

void DFS(int s, Vector *adjLIst, bool *visited)
{
    visited[s] = 1;
    cout << s << "->";
    for (auto i = adjLIst[s].begin(); i != adjLIst[s].end(); i++)
    {
        if (!visited[*i])
        {
            DFS(*i, adjLIst, visited);
        }
    }
}

void DFSinit(int n, Vector *adjList)
{
    for (int i = 0; i < n; i++)
    {
        bool visited[n] = {0};
        cout << "[" << i << "] -> ";
        DFS(i, adjList, visited);
        cout << "\n";
    }
}

void BFS(int s, Vector *adjList, int n){
    queue<int> q;
    bool visited[n] = {0};
    q.push(s);
    visited[s] = 1;
    while (!q.empty())
    {
        int front = q.front();
        for (auto i = adjList[front].begin(); i < adjList[front].end(); i++)
        {
            if(!visited[*i]){
                q.push(*i);
                visited[*i] = 1;
            }
        }
        cout << front << "->";
        q.pop();
    }
    
}

int main()
{
    int n = 3;
    Vector *adjList = createAdjList(n);
    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 0);
    printAdjList(adjList, n);
    removeEdge(adjList, 0, 1);
    cout << "AFTER REMOVE 0 -> 1 Edge" << endl;
    printAdjList(adjList, n);
    DFSinit(n, adjList);
    BFS(0, adjList, n);
}