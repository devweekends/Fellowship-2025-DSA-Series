/*
✅ Approach: Two Pointers with One Allowed Deletion

Problem:
You're given a string and allowed to **remove at most one character**.
Check if it's possible to make the string a **palindrome** after that.

💡 Idea:
Use the **Two Pointer** approach to compare characters from both ends.

Steps:
1. Start with two pointers: `l = 0` (left), `r = s.size() - 1` (right).
2. Move both inward as long as characters match: `s[l] == s[r]`
3. If a mismatch occurs:
   - You have **one chance** to skip either `s[l]` or `s[r]`
   - Check both possibilities:
     🔹 Skip left → Check if `s[l+1..r]` is a palindrome  
     🔹 Skip right → Check if `s[l..r-1]` is a palindrome
4. If either case is valid, return `true`
5. If no mismatches or a valid skip found → the string is a palindrome with at most 1 deletion

✅ Time: O(n), Space: O(1)
*/

class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0 , r= s.size()-1;
        while( l<r){
            if(s[l] != s[r]){
                int l1 = l+1; 
                int r1 = r ;
                int l2 = l;
                int r2 = r-1;
                while(l1<r1 && s[l1] == s[r1]){
                    l1++;
                    r1--;
                }
                while(l2 < r2 && s[l2] ==  s[r2]){
                    l2++;
                    r2--;
                }
                return l1>=r1 || l2 >= r2;
            }
            l++;
            r--;
        }
        return true;
    }
};