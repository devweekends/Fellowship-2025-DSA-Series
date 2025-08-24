/*
Problem: 127. Word Ladder

This problem can be solved using BFS to find the shortest path.
Key insights:
1. Use BFS to find the shortest path from beginWord to endWord
2. For each word, generate all possible one-letter transformations
3. Check if the transformed word is in the wordList
4. Use a visited set to avoid cycles
5. Return the number of steps in the shortest path

Time Complexity: O(26 * L * N) where L is word length and N is wordList size
Space Complexity: O(N) - queue and visited set
*/

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Convert wordList to set for O(1) lookup
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If endWord is not in wordList, return 0
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        int level = 1;
        
        while (!q.empty()) {
            int size = q.size();
            
            // Process all words at current level
            for (int i = 0; i < size; i++) {
                string current = q.front();
                q.pop();
                
                // If we reached endWord, return the level
                if (current == endWord) {
                    return level;
                }
                
                // Generate all possible one-letter transformations
                for (int j = 0; j < current.length(); j++) {
                    char original = current[j];
                    
                    // Try all 26 letters
                    for (char c = 'a'; c <= 'z'; c++) {
                        current[j] = c;
                        
                        // Check if the new word is in wordList and not visited
                        if (wordSet.find(current) != wordSet.end() && 
                            visited.find(current) == visited.end()) {
                            q.push(current);
                            visited.insert(current);
                        }
                    }
                    
                    // Restore original character
                    current[j] = original;
                }
            }
            
            level++;
        }
        
        return 0;  // No path found
    }
};
