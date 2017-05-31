#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

class Graph{
private:
  vector< vector< int > > adj;
public:
  Graph(int n);
  void add_edge(int u, int v);
  int find(vector<int> parent, int u);
  void create_union(vector<int>& parent, vector<int>& rank, int u, int v);
};

Graph::Graph(int n){
  vector<vector<int> > adjMat(n);
  adj = adjMat;
}

void Graph::add_edge(int u, int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int Graph::find(vector<int> parent, int u){
  if(parent[u] == u){
    return u;
  }
  return find(parent, parent[u]);
}

void Graph::create_union(vector<int>& parent, vector<int>& rank, int u, int v){
  int uroot = find(parent, u);
  int vroot = find(parent, v);

  if(rank[uroot] < rank[vroot]){
    parent[uroot] = vroot;
  }else if(rank[uroot] > rank[vroot]){
    parent[vroot] = uroot;
  }else{
    parent[vroot] = uroot;
    rank[uroot]++;
  }
}

int main(){
  int q;
  cin >> q;
  for(int j = 0; j < q; j++){
    int n, m, c_lib, c_road;
    cin >> n >> m >> c_lib >> c_road;
    vector<int> parent, rank(n, 0);
    int total_weight = 0;
    for(int i = 0; i < n; i++){
      parent.push_back(i);
    }// vector<Edge> edges;
    Graph g(n);
    for(int i = 0; i < m; i++){
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      g.add_edge(u, v);
      // edges.push_back(e);
      g.create_union(parent, rank, u, v);
    }
    if(c_lib <= c_road){
      cout << c_lib * n << endl;
      continue;
    }
    unordered_set<int> set;
    int cost = 0;
    for(int i = 0; i < n; i++){
      if(set.find(g.find(parent, i)) == set.end()){
        cost += c_lib;
        set.insert(g.find(parent, i));
      }else{
        cost += c_road;
      }
    }
    cout << cost << endl;
  }
}
