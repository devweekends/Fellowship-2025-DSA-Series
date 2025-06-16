/*
✅ Approach: Two Pointer Technique

We're given a **sorted array**, and we need to **remove duplicates in-place**, returning the length of the new array with unique elements at the beginning.

💡 Why Two Pointers?
Since the array is sorted, all duplicates will be **next to each other**.
We can use two pointers:
- `i` → Points to the **last unique element** found
- `j` → Goes through the array to find **new unique elements**

🔄 How it works:
1. Start with `i = 0` (first element is always unique)
2. Move `j` from index 1 to end:
   - If `nums[j] != nums[i]`, it means a new unique element is found
   - So, place it at `i+1`, and move `i` forward
3. Finally, return `i + 1` as the count of unique elements

✅ This modifies the input array to have all unique elements at the start.
📦 Time: O(n), Space: O(1) — done in-place without extra space.
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int n = nums.size();
       int i  =0;
         for(int j = i+1 ; j<n ;j++){
              if(nums[j] != nums[i]){
                nums[i+1] = nums[j];
                i++;
              }
         }
         return (i+1);
       }
};