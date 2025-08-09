/*
Approach: Greedy Algorithm

The greedy approach is to extend the current partition until we've seen all occurrences
of every character in the current partition.

Algorithm:
1. First pass: record the last occurrence index of each character
2. Second pass: 
   - Track the current partition's end (furthest last occurrence)
   - When we reach the current partition's end, we can safely partition here
   - Add the partition size and start a new partition

Time Complexity: O(n)
Space Complexity: O(1) - fixed size array for 26 lowercase letters
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastOccurrence;
        
        // Record last occurrence of each character
        for (int i = 0; i < s.length(); i++) {
            lastOccurrence[s[i]] = i;
        }

        vector<int> partitions;
        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++) {
            // Extend current partition to include all occurrences of current character
            end = max(end, lastOccurrence[s[i]]);
            
            // If we've reached the end of current partition
            if (i == end) {
                partitions.push_back(end - start + 1);
                start = i + 1;
            }
        }

        return partitions;
    }
};
