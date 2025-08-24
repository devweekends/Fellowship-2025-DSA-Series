/*
Problem: 210. Course Schedule II

This problem requires finding a topological order using DFS.
Key insights:
1. Build an adjacency list representation of the graph
2. Use DFS to detect cycles and build topological order
3. If there's a cycle, return empty array
4. Use a visited array to track visited nodes and detect cycles
5. Build the result in reverse topological order

Time Complexity: O(V + E) - we visit each node and edge once
Space Complexity: O(V + E) - adjacency list and recursion stack
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list
        vector<vector<int>> graph(numCourses);
        for (const auto& prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
        }
        
        // Track visited nodes: 0 = unvisited, 1 = visiting, 2 = visited
        vector<int> visited(numCourses, 0);
        vector<int> result;
        
        // Check for cycles and build topological order
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (hasCycle(graph, visited, result, i)) {
                    return {};  // Cycle detected
                }
            }
        }
        
        // Reverse the result to get topological order
        reverse(result.begin(), result.end());
        return result;
    }
    
private:
    bool hasCycle(vector<vector<int>>& graph, vector<int>& visited, 
                  vector<int>& result, int node) {
        // Mark node as visiting
        visited[node] = 1;
        
        // Check all neighbors
        for (int neighbor : graph[node]) {
            if (visited[neighbor] == 1) {
                // Found a back edge (cycle)
                return true;
            } else if (visited[neighbor] == 0) {
                if (hasCycle(graph, visited, result, neighbor)) {
                    return true;
                }
            }
        }
        
        // Mark node as visited and add to result (post-order)
        visited[node] = 2;
        result.push_back(node);
        return false;
    }
};
