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
        adjmet[v][u] = 1;  
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


// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int vertice = 5; 
//     int edge = 3;   

   
//     vector<vector<bool>> adjmet(vertice, vector<bool>(vertice, 0));

    
//     vector<pair<int,int>> edges = {
//         {0,1}, {1,2}, {3,4}
//     };


//     for (auto e : edges) {
//         int u = e.first;
//         int v = e.second;
//         adjmet[u][v] = 1;
//         adjmet[v][u] = 1;  
//     }

    
//     cout << "Adjacency Matrix:" << endl;
//     for (int i = 0; i < vertice; i++) {
//         for (int j = 0; j < vertice; j++) {
//             cout << adjmet[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }



// Adjacency Matrix for Undirected and Weighted graph:



// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int vertice = 5; 
//     int edge = 3;  
    
   
//     vector<vector<int>> adjmet(vertice, vector<int>(vertice, 0));

   
//     vector<tuple<int,int,int>> edges = {
//         {0,1,4},   
//         {1,2,7},   
//         {3,4,2}    
//     };

    
//     for (auto e : edges) {
//         int u, v, w;
//         tie(u, v, w) = e;
//         adjmet[u][v] = w;
//         adjmet[v][u] = w; 
//     }


//     cout << "Adjacency Matrix (Undirected & Weighted):" << endl;
//     for (int i = 0; i < vertice; i++) {
//         for (int j = 0; j < vertice; j++) {
//             cout << adjmet[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }



//Adjacency Matrix for Directed and Unweighted graph:


// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int vertice = 5; 
//     int edge = 3;   

   
//     vector<vector<bool>> adjmet(vertice, vector<bool>(vertice, 0));

    
//     vector<pair<int,int>> edges = {
//         {0,1}, {1,2}, {3,4}
//     };


//     for (auto e : edges) {
//         int u = e.first;
//         int v = e.second;
//         adjmet[u][v] = 1;
        
//     }

    
//     cout << "Adjacency Matrix:" << endl;
//     for (int i = 0; i < vertice; i++) {
//         for (int j = 0; j < vertice; j++) {
//             cout << adjmet[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }









