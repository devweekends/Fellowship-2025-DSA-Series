/**
 * Approach:
 * The problem is to reorder a linked list in the specific pattern:
 * L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...
 * 
 * To achieve this, we follow three main steps:
 * 
 * 1. **Find the middle of the list**:
 *    - Use the slow and fast pointer approach to locate the middle node.
 *    - This splits the list into two halves.
 * 
 * 2. **Reverse the second half of the list**:
 *    - Reverse the list starting from the node after the middle.
 * 
 * 3. **Merge the two halves**:
 *    - Interleave nodes from the first half and the reversed second half.
 * 
 * Time Complexity: O(N), where N is the number of nodes in the list.
 * Space Complexity: O(1), in-place operations are used.
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
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return;

        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        slow->next = nullptr;

        // Step 3: Merge the two halves
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};
