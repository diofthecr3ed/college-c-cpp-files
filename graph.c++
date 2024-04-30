#include <iostream>
#include<map>
#include<queue>
#include<list>
#include<stack>


using namespace std;

void addEdge(map <int, list <int>> & adjlist, int u, int v, bool isDirected) {
  adjlist[u].push_back(v);
  if (!isDirected) {
    adjlist[v].push_back(u);
  }

}

void BFS(map <int, list <int>> & adjlist, int startNode) {
  map <int, bool> visited;
  queue <int> q;

  q.push(startNode);
  visited[startNode] = true;

  while (!q.empty()) {
    int current = q.front();
    q.pop();
    cout << current << " ";

    for (int neighbor: adjlist.at(current)) {
      if (!visited[neighbor]) {
        q.push(neighbor);
        visited[neighbor] = true;
      }
    }
  }
}

void DFS(map < int, list < int >> & adjlist, int s) {
  map < int, bool > visited;

  stack < int > stack;
  stack.push(s);

  while (!stack.empty()) {
    int s = stack.top();
    stack.pop();
    if (!visited[s]) {
      cout << s << " ";
      visited[s] = true;
    }
    for (auto i = adjlist[s].begin(); i != adjlist[s].end(); ++i) {
      if (!visited[ *i]) {
        stack.push( *i);
      }
    }
  }
}

int main() {

  int numNodes, numEdges;
  bool isDirected;

  cout << "Enter the number of nodes in the graph: ";
  cin >> numNodes;

  cout << "Enter the number of edges in the graph: ";
  cin >> numEdges;

  cout << "Is the graph directed? (1 for yes, 0 for no): ";
  cin >> isDirected;

  map < int, list < int >> adjlist;

  cout << "enter the edges :" << endl;

  for (int i = 0; i < numEdges; i++) {
    int u, v;
    cin >> u >> v;
    addEdge(adjlist, u, v, isDirected);
  }
  int start;
  cout << "enter the starting node for BFS";
  cin >> start;

  cout << "BFS TRAVERSAL   FROM NODE: " << start << "   :  ";
  BFS(adjlist, start);
  return 0;

}