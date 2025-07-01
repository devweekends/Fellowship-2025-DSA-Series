/**
 * Approach:
 * We use Floyd’s Cycle Detection Algorithm (also known as the Tortoise and Hare algorithm):
 * - Use two pointers: `slow` and `fast`.
 * - `slow` moves one step at a time, while `fast` moves two steps at a time.
 * - If there is no cycle, `fast` will eventually reach the end (NULL).
 * - If there is a cycle, `fast` and `slow` will eventually meet at some point within the cycle.
 * - We return true if they meet, otherwise false if the loop exits without meeting.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};
