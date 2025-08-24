/*
Problem: 131. Palindrome Partitioning

This problem uses backtracking to find all valid palindrome partitions.
Key insights:
1. We try to partition the string at different positions
2. For each partition, we check if the substring is a palindrome
3. If it is a palindrome, we recursively partition the remaining string
4. We backtrack by removing the last partition to try different splits
5. When we've processed the entire string, we add the current partition to our result
6. We use a helper function to check if a string is a palindrome

Time Complexity: O(n * 2^n) - we try 2^n partitions and check palindromes
Space Complexity: O(n) - recursion stack depth
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(s, 0, current, result);
        return result;
    }
    
private:
    void backtrack(string& s, int start, vector<string>& current, vector<vector<string>>& result) {
        // Base case: if we've processed the entire string
        if (start == s.length()) {
            result.push_back(current);
            return;
        }
        
        // Try partitioning at different positions
        for (int end = start; end < s.length(); end++) {
            // Check if the substring from start to end is a palindrome
            if (isPalindrome(s, start, end)) {
                // Add the palindrome substring to current partition
                current.push_back(s.substr(start, end - start + 1));
                
                // Recursively partition the remaining string
                backtrack(s, end + 1, current, result);
                
                // Backtrack: remove the last partition
                current.pop_back();
            }
        }
    }
    
    // Helper function to check if a substring is a palindrome
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
