/*
Problem: 133. Clone Graph

This problem requires a deep copy of a graph using DFS or BFS.
Key insights:
1. Use a hash map to track which nodes have been cloned
2. Create a new node for each node we visit
3. Copy the neighbors recursively
4. Handle the case where a node has already been cloned
5. Avoid infinite recursion by checking the hash map

Time Complexity: O(V + E) - we visit each node and edge once
Space Complexity: O(V) - hash map to store cloned nodes
*/

#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        // Hash map to track cloned nodes
        unordered_map<Node*, Node*> visited;
        
        return dfs(node, visited);
    }
    
private:
    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        // If node has already been cloned, return the clone
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        
        // Create a new node
        Node* clone = new Node(node->val);
        visited[node] = clone;
        
        // Clone all neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, visited));
        }
        
        return clone;
    }
};
