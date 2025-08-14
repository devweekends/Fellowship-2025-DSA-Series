class Solution {
private:
    vector<vector<string>> result;
    
    // Helper function to check if a substring is palindrome
    bool isPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    void backtrack(const string& s, vector<string>& current, int start) {
        // Base case: if we've processed the entire string
        if (start >= s.length()) {
            result.push_back(current);
            return;
        }
        
        // Try all possible substring lengths from current position
        for (int end = start; end < s.length(); end++) {
            // Check if substring from start to end is palindrome
            if (isPalindrome(s, start, end)) {
                // Make choice: add palindrome substring
                string substring = s.substr(start, end - start + 1);
                current.push_back(substring);
                
                // Recurse with next position
                backtrack(s, current, end + 1);
                
                // Backtrack: remove substring
                current.pop_back();
            }
        }
    }
    
public:
    vector<vector<string>> partition(string s) {
        vector<string> current;
        backtrack(s, current, 0);
        return result;
    }
};

/*
Time Complexity: O(n * 2^n) where n is the length of string
Space Complexity: O(n) for recursion stack
*/ 