//Adjacency Matrix for Directed and Unweighted graph:


#include <iostream>
#include <vector>
using namespace std;

int main() {
    int vertice = 5; 
    int edge = 3;   

   
    vector<vector<bool>> adjmet(vertice, vector<bool>(vertice, 0));

    
    vector<pair<int,int>> edges = {
        {0,1}, {1,2}, {3,4}
    };


    for (auto e : edges) {
        int u = e.first;
        int v = e.second;
        adjmet[u][v] = 1;
        
    }

    
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < vertice; i++) {
        for (int j = 0; j < vertice; j++) {
            cout << adjmet[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}









