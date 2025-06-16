// ✅ Approach:
// We treat the array like a linked list where:
// - Each index represents a node.
// - The value at each index points to the next node (like a pointer).
// Since one number is repeated, it causes a cycle in this "linked list".
// To detect the cycle, we use Floyd’s Tortoise and Hare algorithm:
//   1. Initialize two pointers: slow and fast, both starting from index 0.
//   2. Move slow one step at a time (slow = nums[slow]).
//      Move fast two steps at a time (fast = nums[nums[fast]]).
//   3. When they meet, it confirms a cycle exists.
//   4. Reset slow to start, move both one step at a time until they meet again.
//   5. The point where they meet is the duplicate number (entry point of the cycle).

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect intersection point in cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find the start of the cycle (duplicate number)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return fast;
    }
};
