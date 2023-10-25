#include <iostream>
#include <vector>
using namespace std;

typedef struct Edge {
  int u, v;
} Edge;

typedef struct Vertex {
  bool visited;
  int parent;
} Vertex;

bool isCycle(int v, int parent, vector<Vertex> &vertices, const vector<Edge> &edges) {
  vertices[v].visited = true;
  vertices[v].parent = parent;

  for (const Edge& edge : edges) {
    if (edge.u == v || edge.v == v) {
      int sibling = (edge.u == v) ? edge.v : edge.u;
      if (!vertices[sibling].visited) {
        if (isCycle(sibling, v, vertices, edges)) {
          return true;
        }
      } else if (sibling != parent) {
        return true;
      }
    }
  }
  return false;
}

bool isConnected(const vector<Vertex>& vertices) {
  for (const Vertex& vertex : vertices) {
    if (!vertex.visited) {
      return false;
    }
  }
  return true;
}

bool isTree(const vector<Edge>& edges, int V, int E) {
  vector<Vertex> vertices(V, {false, -1});

  if (isCycle(0, -1, vertices, edges)) {
    return false;
  }

  if (!isConnected(vertices)) {
    return false;
  }

  return true;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<Edge> edges(m);
  for (int i = 0; i < m; i++) {
    cin >> edges[i].u >> edges[i].v;
  }

  if (isTree(edges, n, m)) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}