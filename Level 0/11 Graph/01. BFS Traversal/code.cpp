#include <vector>
#include <queue>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> order;
    vector<int> visited(V, 0);
    queue<int> q;
    q.push(0);
    visited[0] = 1;
    while(!q.empty()){
        int node = q.front(); q.pop();
        order.push_back(node);
        for(int neighbor : adj[node]){
            if(!visited[neighbor]){
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
    return order;
}


