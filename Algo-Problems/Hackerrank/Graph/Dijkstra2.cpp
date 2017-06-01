#include <bits/stdc++.h>

#define INF INT_MAX
using namespace std;
typedef pair<int, int> iPair;

class Graph{
private:
  int n;  // number of nodes
  vector<list<pair<int, int> > > adj;
public:
  Graph(int n);
  void addEdge(int u, int v, int wt);
  void shortestPath(int s);
};

Graph::Graph(int n):adj(n){
  this->n = n;
};

void Graph::addEdge(int u, int v, int wt){
  adj[u].push_back(make_pair(v, wt));
  adj[v].push_back(make_pair(u, wt));
}

void Graph::shortestPath(int src){
  priority_queue<iPair, vector<iPair>, greater<iPair> > pq;

  vector<int> dist(n, INF);
  vector<bool> visited(n, false);
  pq.push(make_pair(0, src));
  dist[src] = 0;
  while(!pq.empty()){
    int u = pq.top().second;
    pq.pop();
    if(visited[u])
      continue;
    visited[u] = true;
    list<pair<int, int> >::iterator it;
    for(it = adj[u].begin(); it != adj[u].end(); ++it){
      int v = (*it).first;
      int weight = (*it).second;
      if(dist[v] > dist[u] + weight){
        dist[v] = dist[u] + weight;
        pq.push(make_pair(dist[v], v));
      }
    }
   
  }
  for(int i = 0; i < n; i++){
    if(dist[i] == INF){
      printf("%d ", -1);
      continue;
    }
    if(i != src)
      printf("%d ", dist[i]);
  }
  printf("\n");
}

int main(){
  int t;
  scanf("%d", &t);
  for(int i = 0; i < t; i++){
    int n, m;
    scanf("%d%d", &n, &m);
    Graph g(n);
    for(int j = 0; j < m; j++){
      int u, v, wt;
      scanf("%d%d%d", &u, &v, &wt);
      u--;
      v--;
      g.addEdge(u, v, wt);
    }
    int s;
    scanf("%d", &s);
    g.shortestPath(s-1);
  }
}