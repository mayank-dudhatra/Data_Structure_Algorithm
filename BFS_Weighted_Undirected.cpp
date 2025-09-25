// Weighted and Undirected



#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void BFS(int start, vector<vector<pair<int,int>>>& adj, int vertices){
    vector<bool> visited(vertices, false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int i = 0; i < adj[node].size(); i++){
            int neighbor = adj[node][i].first; 
            if(!visited[neighbor]){
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int vertices = 5;
    vector<vector<pair<int,int>>> adj(vertices);

    
    adj[0].push_back({1, 2}); 
    adj[1].push_back({0, 2}); 

    adj[0].push_back({2, 4}); 
    adj[2].push_back({0, 4}); 

    adj[1].push_back({3, 7}); 
    adj[3].push_back({1, 7}); 

    adj[2].push_back({3, 1}); 
    adj[3].push_back({2, 1}); 

    adj[3].push_back({4, 3}); 
    adj[4].push_back({3, 3}); 

    cout << "BFS Traversal: ";
    BFS(0, adj, vertices);

   
    cout << "\nAdjacency List (with weights):\n";
    for(int i=0; i<vertices; i++){
        cout << i << " -> ";
        for(int j=0; j<adj[i].size(); j++){
            cout << "(" << adj[i][j].first << "," << adj[i][j].second << ") ";
        }
        cout << endl;
    }

    return 0;
}
