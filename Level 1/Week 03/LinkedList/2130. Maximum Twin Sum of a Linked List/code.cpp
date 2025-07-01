/**
 * Approach:
 * The problem is to find the maximum twin sum in a linked list of even length.
 * A twin sum is defined as the sum of a node and its twin node from the other half of the list.
 * 
 * Steps:
 * 1. Use the slow and fast pointer technique to find the middle of the list.
 * 2. Reverse the second half of the list.
 * 3. Traverse both halves simultaneously, calculating the twin sum at each step.
 * 4. Track the maximum twin sum during traversal.
 * 
 * Time Complexity: O(N) – One pass to find the middle, one to reverse, one to compute max sum.
 * Space Complexity: O(1) – Reversal is done in-place without extra space.
 */

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* prev = nullptr;
        while(slow) {
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        // Calculate max twin sum
        int maxSum = 0;
        ListNode* left = head;
        ListNode* right = prev;

        while (right) {
            maxSum = max(maxSum, left->val + right->val);
            left = left->next;
            right = right->next;
        }
        return maxSum;
    }
};
