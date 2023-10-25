#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef vector<int> Vector;
Vector *createGraph(int n)
{
    return new Vector[n];
}

void addEdge(Vector *vector, int u, int v)
{
    vector[u].push_back(v);
    vector[v].push_back(u);
}
void printGraph(Vector *vector, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "[" << i << "]->";
        for (int j = 0; j < vector[i].size(); j++)
        {
            cout << vector[i].at(j) << "->";
        }
        cout << "\n";
    }
}

void removeEdge(Vector *vector, int u, int v)
{
    for (int i = 0; i < vector[u].size(); i++)
    {
        if (vector[u].at(i) == v)
        {
            vector[u].erase(vector[u].begin() + i);
        }
    }
}

void DFS(Vector *vector, int u, bool *visited)
{
    visited[u] = 1;
    cout << u;
    for (auto i = vector[u].begin(); i != vector[u].end(); i++)
    {
        if (!visited[*i])
        {
            DFS(vector, *i, visited);
        }
    }
}

void DFSinit(Vector *vector, int s, int n)
{
    bool visited[n] = {0};
    DFS(vector, s, visited);
}

void BFS(Vector *vector, int s, int n)
{
    queue<int> q;
    bool visited[n] = {0};
    q.push(s);
    visited[s] = 1;
    while (!q.empty())
    {
        int front = q.front();
        for (auto i = vector[front].begin(); i != vector[front].end(); i++)
        {
            if (!visited[*i])
            {
                visited[*i] = 1;
                q.push(*i);
            }
            
        }
        cout << front;
        q.pop();
    }
}

int main()
{
    int n = 5;
    Vector *vector = createGraph(n);
    addEdge(vector, 0, 1);
    addEdge(vector, 0, 3);
    addEdge(vector, 1, 2);
    addEdge(vector, 4, 1);
    addEdge(vector, 2, 4);
    printGraph(vector, n);
    cout << "-----"
         << "\n";
    // removeEdge(vector, 0, 2);
    printGraph(vector, n);

    for (int i = 0; i < n; i++)
    {
        DFSinit(vector, i, n);
        cout << endl;
    }

    BFS(vector, 0, n);
    return 0;
}