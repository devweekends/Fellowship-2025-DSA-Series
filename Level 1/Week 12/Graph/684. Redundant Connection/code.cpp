/*
Problem: 684. Redundant Connection

This problem can be solved using Union-Find (Disjoint Set).
Key insights:
1. Initialize Union-Find data structure
2. Process edges one by one
3. If adding an edge creates a cycle, that edge is redundant
4. Return the first edge that creates a cycle
5. Use path compression and union by rank for efficiency

Time Complexity: O(n * α(n)) where α is the inverse Ackermann function
Space Complexity: O(n) - parent and rank arrays
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        // Initialize Union-Find
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        
        // Process each edge
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            // If both nodes are already in the same set, this edge creates a cycle
            if (find(parent, u) == find(parent, v)) {
                return edge;
            }
            
            // Union the two sets
            unionSets(parent, rank, u, v);
        }
        
        return {};
    }
    
private:
    // Find with path compression
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) {
            parent[x] = find(parent, parent[x]);
        }
        return parent[x];
    }
    
    // Union by rank
    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        
        if (rootX == rootY) {
            return;
        }
        
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }
};
