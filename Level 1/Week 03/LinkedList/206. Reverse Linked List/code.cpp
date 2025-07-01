/**
 * Approach:
 * We will use the **iterative method** to reverse the singly-linked list.
 * - Initialize three pointers: `prev` as `nullptr`, `current` as `head`, and `nextNode` for temporary storage.
 * - Iterate through the list, and for each node:
 *     - Save `current->next` to `nextNode`.
 *     - Reverse the link: point `current->next` to `prev`.
 *     - Move `prev` and `current` one step forward.
 * - At the end, `prev` will be the new head of the reversed list.
 * - Return `prev`.
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* nextNode = current->next; // store next
            current->next = prev;               // reverse current node's pointer
            prev = current;                     // move prev and current one step forward
            current = nextNode;
        }

        return prev;
    }
};
