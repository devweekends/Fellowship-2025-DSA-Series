/*
Approach (Sliding Window + Frequency Hashing):

We need to find the smallest window in `s` that contains all characters from `t`.

⚙️ Logic:
1. Use two frequency arrays:
   - `hashT` → frequency of characters in `t`.
   - `hashS` → current frequency of characters in the window from `s`.
2. Expand the window by moving the `right` pointer and include characters.
3. Use a counter `cnt` to track how many characters from `t` are satisfied in the current window.
4. Once all required characters are in the window (`cnt == t.size()`), try to shrink the window from the left (`left++`) to find the minimum possible window.
5. During each valid window, update the `minLen` and store the starting index.

✅ Time Complexity: O(n)
✅ Space Complexity: O(256) = O(1) (constant space for ASCII character counts)

📌 Edge Case:
- If no such window exists, return an empty string.
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty())
            return "";

        vector<int> hashS(256, 0);

        vector<int> hashT(256, 0);

        for (int i = 0; i < t.size(); i++) {
            hashT[t[i]]++;
        }
        int left = 0;
        int cnt = 0;
        int minLen = INT_MAX;
        int sIndex = 0;
        for (int right = 0; right < s.size(); right++) {
            hashS[s[right]]++;

        if(hashT[s[right]] > 0 && hashS[s[right]] <= hashT[s[right]]){
            cnt++;
        }

        while (cnt == t.size()) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                sIndex = left;
            }
            hashS[s[left]]--;
                    if(hashT[s[left]] > 0 && hashS[s[left]] < hashT[s[left]]){
                        cnt--;
                    }
                    left++;
        }
        }
        if (minLen == INT_MAX) {
            return ""; 
        } else {
            return s.substr(sIndex, minLen); 
        }
    }
};
