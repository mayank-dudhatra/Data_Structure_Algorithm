// Adjacency List for Directed and Weighted graph:

// Input you have to Enter
// Enter the number of vertices and edges: 5 6
// Enter the edges (u v w): 
// 0 1 3
// 0 2 4
// 1 2 9
// 1 3 6
// 2 4 2
// 3 4 10


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges: ";
    cin >> vertices >> edges;

    // adjacency list with pair (neighbor, weight)
    vector<vector<pair<int, int>>> adjList(vertices);

    cout << "Enter the edges (u v w): " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // undirected graph -> add both u->v and v->u
        adjList[u].push_back({v, w});
        
    }

    cout << "\nAdjacency List of the Weighted Graph:\n";
    for (int i = 0; i < vertices; i++) {
        cout << i << " -> ";
        for (auto &edge : adjList[i]) {
            cout << "(" << edge.first << ", " << edge.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
