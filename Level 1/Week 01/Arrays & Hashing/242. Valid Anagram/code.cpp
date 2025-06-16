/*
Approach:
We determine whether two strings `s` and `t` are anagrams by comparing the frequency of each character.

1. First, check if the lengths of both strings are different.
   - If they are, return false immediately (they can't be anagrams).

2. Use two hash maps (`unordered_map`) to count the frequency of each character in both strings:
   - `countS` for string `s`
   - `countT` for string `t`

3. Iterate through the strings and update the counts.

4. After the loop, compare the two maps:
   - If they are equal, the strings are anagrams → return true.
   - Otherwise, return false.

Time Complexity: O(n), where n is the length of the strings.
Space Complexity: O(1) (constant, since the alphabet size is fixed and small, though technically O(k) where k is the number of unique characters).
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<int, int> countS, countT;
        for (int i = 0; i < s.size(); i++) {
            countS[s[i]]++;
            countT[t[i]]++;
        }
        return countS == countT;
    }
};
