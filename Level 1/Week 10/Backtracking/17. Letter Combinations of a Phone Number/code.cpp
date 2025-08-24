/*
Problem: 17. Letter Combinations of a Phone Number

This problem uses backtracking to generate all possible letter combinations.
Key insights:
1. We build the combination incrementally by choosing one letter at a time
2. For each digit, we try all possible letters that it can represent
3. We use a mapping array to convert digits to letters
4. We backtrack by removing the last added letter to try different combinations
5. When we've processed all digits, we add the complete combination to our result
6. We handle the empty string case separately

Time Complexity: O(4^n) - each digit can represent up to 4 letters
Space Complexity: O(n) - recursion stack depth
*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        
        string current;
        backtrack(digits, 0, current, result);
        return result;
    }
    
private:
    // Mapping of digits to letters
    vector<string> digitMap = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
    
    void backtrack(string& digits, int index, string& current, vector<string>& result) {
        // Base case: if we've processed all digits
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }
        
        // Get the letters for the current digit
        int digit = digits[index] - '0';
        string letters = digitMap[digit];
        
        // Try each letter for the current digit
        for (char letter : letters) {
            // Add the letter to current combination
            current += letter;
            
            // Recursively build the rest of the combination
            backtrack(digits, index + 1, current, result);
            
            // Backtrack: remove the letter
            current.pop_back();
        }
    }
};
