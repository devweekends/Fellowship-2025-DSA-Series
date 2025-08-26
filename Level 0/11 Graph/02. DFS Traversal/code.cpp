#include <vector>
using namespace std;

void dfsRec(int node, vector<int> adj[], vector<int>& visited, vector<int>& order){
    visited[node] = 1;
    order.push_back(node);
    for(int neighbor : adj[node]){
        if(!visited[neighbor]) dfsRec(neighbor, adj, visited, order);
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> order;
    vector<int> visited(V, 0);
    dfsRec(0, adj, visited, order);
    return order;
}


