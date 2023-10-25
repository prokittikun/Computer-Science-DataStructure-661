#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Vector;

Vector *createAdjList(int n){
    return new vector<int>[n];
}

void addEdge(Vector *adjList, int u, int v){
    adjList[u].push_back(v);
    // adjList[v].push_back(u);
}

void removeEdge(Vector *adjList, int u, int v){
    for (int i = 0; i < adjList[u].size(); i++)
    {
        if(adjList[u].at(i) == v){
            adjList[u].erase(adjList[u].begin() + i);
        }
    }
    // for (int i = 0; i < adjList[v].size(); i++)
    // {
    //     if(adjList[v].at(i) == u){
    //         adjList[v].erase(adjList[v].begin() + i);
    //     }
    // }
}

void printAdjList(Vector *adjList, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "[" << i <<"] " << "head ";
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << adjList[i].at(j) << "->";
        }
        cout << endl;
    }
    
}

int main(){
    int n = 5;
    Vector *adjList = createAdjList(n);
    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 4, 1);
    addEdge(adjList, 2, 4);
    printAdjList(adjList, n);
    cout << "-------\n";
    removeEdge(adjList, 0, 3);
    printAdjList(adjList, n);

}

// push_back, at , begin ,end ,size