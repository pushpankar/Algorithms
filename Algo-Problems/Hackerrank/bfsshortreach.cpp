#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Graph{
  vector<vector<int> > adj;
public:
  Graph(int n);
  void addEdge(int u, int v);
  void BFS(int s);
  void print_vector(const vector<int>& v, int s);
};

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
  int q;
  scanf("%d", &q);
  for (int j = 0; j < q; j++){
    int n, m;
    scanf("%d%d", &n, &m);
    Graph g(n+1);
    for(int i = 0; i < m; i++){
      int u, v;
      scanf("%d%d", &u, &v);
      g.addEdge(u,v);
    }
    int s;
    scanf("%d", &s);
    g.BFS(s);
  }
  return 0;
}



Graph::Graph(int n){
  adj.resize(n);
}

void Graph::addEdge(int u, int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}
void Graph::BFS(int s){
  vector<int> distance(adj.size(), -1);
  queue<int> q;
  q.push(s);
  distance[s] = 0;

  while (!q.empty()) {
    vector<int>::iterator it;
    for(it = adj[q.front()].begin(); it != adj[q.front()].end(); it++){
      if (distance[*it] == -1) {
	distance[*it] = distance[q.front()] + 6;
	q.push(*it);
      }
    }
    q.pop();
  }
  print_vector(distance, s);
    
}

void Graph::print_vector(const vector<int>& v, int s){
  for (int i =  1; i < adj.size(); i++) {
    if (i != s){
      cout << v[i] << ' ';
    }
  }
  cout << endl;
}
