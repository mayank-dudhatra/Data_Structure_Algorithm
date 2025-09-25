// Adjacency List for Directed and Unweighted graph:

// Input you have to Enter :---
// Enter the number of vertices and edges: 5 6
// Enter the edges (u v): 
// 0 1 
// 0 2
// 1 2
// 1 3
// 2 4
// 3 4 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

   
    vector<vector<int>> adjList(vertices);

    cout << "Enter the edges (u v): " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v;

        
        adjList[u].push_back(v);
     
    }

    cout << "\nAdjacency List of the Graph:\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
