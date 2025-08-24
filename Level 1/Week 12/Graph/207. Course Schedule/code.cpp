/*
Problem: 207. Course Schedule

This problem can be solved using topological sort or cycle detection.
Key insights:
1. Build an adjacency list representation of the graph
2. Use DFS to detect cycles in the graph
3. If there's a cycle, it's impossible to complete all courses
4. Use a visited array to track visited nodes and detect cycles
5. Return true if no cycles are found

Time Complexity: O(V + E) - we visit each node and edge once
Space Complexity: O(V + E) - adjacency list and recursion stack
*/

#include <vector>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Build adjacency list
        vector<vector<int>> graph(numCourses);
        for (const auto& prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
        }
        
        // Track visited nodes: 0 = unvisited, 1 = visiting, 2 = visited
        vector<int> visited(numCourses, 0);
        
        // Check for cycles starting from each node
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                if (hasCycle(graph, visited, i)) {
                    return false;
                }
            }
        }
        
        return true;
    }
    
private:
    bool hasCycle(vector<vector<int>>& graph, vector<int>& visited, int node) {
        // Mark node as visiting
        visited[node] = 1;
        
        // Check all neighbors
        for (int neighbor : graph[node]) {
            if (visited[neighbor] == 1) {
                // Found a back edge (cycle)
                return true;
            } else if (visited[neighbor] == 0) {
                if (hasCycle(graph, visited, neighbor)) {
                    return true;
                }
            }
        }
        
        // Mark node as visited
        visited[node] = 2;
        return false;
    }
};
