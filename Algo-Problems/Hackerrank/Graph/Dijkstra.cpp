#include <iostream>
#include <vector>
#include <utility>

class Graph{
private:
  vector<vector<pair<int, int> > > adj;
public:
  Graph(int n);
  void addEdge(int u, int v, int wt);
};

class HeapNode{
  int destination;
  int distance;
}

class Heap{
  vector<int> heap;
  void minHeapify(int v);
  void buildMinHeap();
  void swap(int u, int v);
  HeapNode extractMin();
  void decreaseKey(int v, int k);
  int left(int i);
  int right(int i);
}

Graph::Graph(int n):adj(n);

void Graph::addEdge(int u, int v, int wt){
  adj[u].push_back(make_pair(v, wt));
  adj[v].push_back(make_pair(u, wt));
}

void Heap::swap(int u, int v){
  HeapNode temp = heap[u];
  heap[u] = heap[v];
  heap[v] = temp;
}

void Heap::minHeapify(int v){
  int l = left(v);
  int r = right(v);
  int smallest = v;
  if(l <= heap.size() && heap[l].distance < heap[u].distance)
    largest = l;
  if(r <= heap.size() && heap[r].distance < heap[largest].distance)
    smallest = r;
  if(largest != i){
    swap(i, smallest);
    minHeapify(smallest);
  }
    
}

HeapNode Heap::extractMin(){
  HeapNode temp = heap[0];
  heap[0] = heap[heap.size()];
  heap.pop_back();
  minHeapify(0);
  return temp;
}
void Heap::buildMinHeap(){
  for(int i = heap.size()/2; i >= 0; i--){
    minHeapify(i);
  }
}