/**
 * Approach:
 * The problem is to add two numbers represented by two non-empty linked lists,
 * where each node contains a single digit and the digits are stored in reverse order.
 * We return the sum as a new linked list, also in reverse order.
 *
 * Steps:
 * 1. Use a dummy node to simplify result list construction.
 * 2. Traverse both input lists simultaneously, adding corresponding digits along with any carry.
 * 3. Create a new node for each digit of the result (sum % 10) and move the carry forward (sum / 10).
 * 4. If a carry remains after the loop, add a new node with the carry value.
 *
 * Time Complexity: O(max(N, M)) where N and M are lengths of the two lists.
 * Space Complexity: O(max(N, M)) for the result list.
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;

        while (temp1 != NULL || temp2 != NULL) {
            int sum = carry;
            if (temp1)
                sum += temp1->val;
            if (temp2)
                sum += temp2->val;

            ListNode* add = new ListNode(sum % 10);
            carry = sum / 10;

            curr->next = add;
            curr = curr->next;

            if (temp1) temp1 = temp1->next;
            if (temp2) temp2 = temp2->next;
        }

        if (carry) {
            ListNode* add2 = new ListNode(carry);
            curr->next = add2;
        }

        return dummy->next;
    }
};
