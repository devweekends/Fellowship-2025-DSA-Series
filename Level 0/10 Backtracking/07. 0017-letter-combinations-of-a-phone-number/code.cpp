class Solution {
private:
    vector<string> result;
    vector<string> digitMap = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    void backtrack(const string& digits, string& current, int index) {
        // Base case: if we've processed all digits
        if (index >= digits.length()) {
            if (!current.empty()) {
                result.push_back(current);
            }
            return;
        }
        
        // Get the letters for current digit
        int digit = digits[index] - '0';
        string letters = digitMap[digit];
        
        // Try each letter for current digit
        for (char letter : letters) {
            // Make choice: add letter
            current += letter;
            
            // Recurse to next digit
            backtrack(digits, current, index + 1);
            
            // Backtrack: remove letter
            current.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return result;
        }
        
        string current;
        backtrack(digits, current, 0);
        return result;
    }
};

/*
Time Complexity: O(4^n) where n is the length of digits
Space Complexity: O(n) for recursion stack
*/ 