/*
Approach (Sliding Window with Frequency Count):

We aim to find the length of the longest substring that can be made of the same character after replacing at most `k` characters.

⚙️ Logic:
1. Use a sliding window defined by two pointers: `left` and `right`.
2. Maintain a frequency array `hash[26]` to count letters in the current window.
3. Track the most frequent character count in the window as `maxfre`.
4. If the number of characters to be replaced → `(right - left + 1) - maxfre` > `k`, then shrink the window from the left.
5. At every step, update the maximum window length.

✅ Time Complexity: O(n)
✅ Space Complexity: O(1) – only 26 alphabet characters

📌 Note:
We don't shrink the window on every invalid step — only when needed. This helps us maintain a valid window efficiently.
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxLen = 0;
        int maxfre = 0;
        vector<int> hash(26, 0);

        for (int right = 0; right < s.size(); right++) {
            hash[s[right] - 'A']++;
            maxfre = max(maxfre, hash[s[right] - 'A']);

            if ((right - left + 1) - maxfre > k) {
                hash[s[left] - 'A']--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
