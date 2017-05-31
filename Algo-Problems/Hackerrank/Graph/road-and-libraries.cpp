#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

class Graph{
private:
  vector<vector<long> > adj;
public:
  vector<bool> visited;
  Graph(long n);
  void add_edge(long u, long v);
  long find(vector<long> parent, long u);
  void create_union(vector<long>& parent, vector<long>& rank, long u, long v);
  void dfsUtil(long start);
};

Graph::Graph(long n):adj(n),visited(n, false){
}

void Graph::add_edge(long u, long v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

long Graph::find(vector<long> parent, long u){
  if(parent[u] == u){
    return u;
  }
  return find(parent, parent[u]);
}

void Graph::create_union(vector<long>& parent, vector<long>& rank, long u, long v){
  long uroot = find(parent, u);
  long vroot = find(parent, v);

  if(rank[uroot] < rank[vroot]){
    parent[uroot] = vroot;
  }else if(rank[uroot] > rank[vroot]){
    parent[vroot] = uroot;
  }else{
    parent[vroot] = uroot;
    rank[uroot]++;
  }
}

void Graph::dfsUtil(long start){
  for(vector<long>::iterator it = adj[start].begin(); it != adj[start].end(); it++){
    if(!visited[*it]){
      visited[*it] = true;
      dfsUtil(*it);
    }
  }
}

int main(){
  long q;
  cin >> q;
  for(long j = 0; j < q; j++){
    long n, m, c_lib, c_road;
    cin >> n >> m >> c_lib >> c_road;
    vector<long> parent, rank(n, 0);
    for(long i = 0; i < n; i++){
      parent.push_back(i);
    }// vector<Edge> edges;
    Graph g(n);
    for(long i = 0; i < m; i++){
      long u, v;
      cin >> u >> v;
      u--;
      v--;
      g.add_edge(u, v);
      // edges.push_back(e);
      // g.create_union(parent, rank, u, v);
    }
    if(c_lib <= c_road){
      cout << c_lib * n << endl;
      continue;
    }
    long s = 0; // s is seperate components
    for(long i = 0; i < n; i++){
      if(!g.visited[i]){
        g.dfsUtil(i);
        s++;
      }
    }
    
    cout << (s * c_lib) + ((n - s) * c_road) << endl;
  }
  return 0;
}
