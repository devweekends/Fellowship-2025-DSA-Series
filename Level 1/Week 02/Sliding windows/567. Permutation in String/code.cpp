/*
Approach (Sliding Window + Frequency Hashing):

We want to check if any permutation of `s1` is a substring of `s2`.

⚙️ Logic:
1. A permutation has the same character frequencies as the original string.
2. We create a fixed-size sliding window of length `s1.size()` on `s2`.
3. For each window:
   - Maintain frequency arrays for `s1` and the current window in `s2`.
   - If the frequency arrays match, return `true` → permutation found.
4. Slide the window by removing the leftmost character and adding the next.

✅ Time Complexity: O(n)
✅ Space Complexity: O(1) → constant space (26-letter frequency arrays)

📌 Note:
We use `==` to compare both frequency arrays. It works because both are fixed size (26), allowing fast element-wise comparison.
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<char> hashs1(26, 0);
        vector<char> hashs2(26, 0);
        int s1Len = s1.size();
        int s2Len = s2.size();

        if (s1Len > s2Len)
            return false;

        // Count frequency of characters in s1
        for (int i = 0; i < s1Len; i++) {
            hashs1[s1[i] - 'a']++;
        }

        for (int i = 0; i < s2Len; i++) {
            hashs2[s2[i] - 'a']++;

            // Maintain window size equal to s1 length
            if (i >= s1Len) {
                hashs2[s2[i - s1Len] - 'a']--; // remove character left behind
            }

            // Compare frequency arrays
            if (hashs1 == hashs2) {
                return true;
            }
        }

        return false;
    }
};
