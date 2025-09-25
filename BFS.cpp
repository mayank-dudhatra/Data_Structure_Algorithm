#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<vector<int>> adj, int vertice){
  vector<bool> visited(vertice, 0);
  queue<int> q;
  visited[start] = true;
  q.push(start);
  
  while(!q.empty()){
    int node = q.front();
    q.pop();
    
     cout << node << " ";
    
    for(int i=0; i<adj[node].size(); i++){
      int neighbor = adj[node][i];
      
      if(!visited[neighbor]){
        visited[neighbor] = 1;
        q.push(neighbor);
      }
    }
  }
  
}

int main() {
  
  
  int vertice = 5; 
  
    vector<vector<int>> adj(vertice);

    
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 3};
    adj[3] = {1, 2, 4};
    adj[4] = {3};

    cout << "BFS Traversal: ";
    BFS(0, adj, vertice);
    return 0;
  
  
}