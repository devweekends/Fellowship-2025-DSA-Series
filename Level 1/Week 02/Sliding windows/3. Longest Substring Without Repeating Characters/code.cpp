/*
Approach (Sliding Window + HashSet):

We aim to find the length of the longest substring without repeating characters.

⚙️ Logic:
1. Use a sliding window with two pointers: `left` and `right`.
2. Maintain a hash set to track characters in the current window.
3. As you expand `right`, check if `s[right]` is already in the window:
   - If it is, shrink the window from the left by removing `s[left]` until it's unique again.
4. Update `maxLen` with the size of the current valid window.

✅ Time Complexity: O(n)
✅ Space Complexity: O(min(n, charset)) – where charset is the size of the character set (e.g., 26 for lowercase, 128 for ASCII)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0;
        int maxLen = 0;
        for (int right = 0; right < s.size(); right++) {
            while (window.find(s[right]) != window.end()) {
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            int windowSize = right - left + 1;
            maxLen = max(maxLen, windowSize);
        }
        return maxLen;
    }
};
