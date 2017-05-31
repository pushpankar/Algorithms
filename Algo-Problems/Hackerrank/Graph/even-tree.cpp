#include <iostream>
#include <vector>

using namespace std;

class Graph{
private:
  vector<vector<int> > adj;
  vector<bool> visited;
public:
  Graph(int n);
  int prunes = 0;
  Graph(long n);
  void add_edge(int u, int v);
  int dfs(int start);
};

Graph::Graph(int n):adj(n), visited(n, false){}

void Graph::add_edge(int u, int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int Graph::dfs(int start){
  int nodes_visited = 0;
  for(vector<int>::iterator it = adj[start].begin(); it != adj[start].end(); it++){
    if(!visited[*it]){
      visited[*it] = true;
      nodes_visited += dfs(*it);
    }
  }
  if(nodes_visited % 2 == 0)
    return nodes_visited + 1;
  else{
    //prune
    prunes++;
    return 0;
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  Graph g(n);
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g.add_edge(u, v);
  }
  g.dfs(1);
  cout << g.prunes - 1 << endl;
}