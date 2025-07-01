/**
 * Approach:
 * We use the two-pointer technique with a dummy node:
 * - First, create a dummy node that points to the head of the list. This helps simplify edge cases like removing the head.
 * - Initialize two pointers, `fast` and `slow`, at the dummy node.
 * - Move the `fast` pointer `n + 1` steps ahead to maintain a gap of `n` between `fast` and `slow`.
 * - Then move both pointers one step at a time until `fast` reaches the end of the list.
 * - At that point, `slow` will be just before the node to be removed.
 * - Adjust the `next` pointer of `slow` to skip the target node.
 * - Return `dummy->next` as the new head of the list.
 * 
 * Time Complexity: O(L), where L is the length of the list.
 * Space Complexity: O(1)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;
        return dummy->next;
    }
};
