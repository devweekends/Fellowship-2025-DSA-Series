/**
 * Approach:
 * We use an **iterative two-pointer technique** to merge two sorted linked lists.
 * - Create a dummy node to serve as the start of the merged list.
 * - Use a pointer `cur` to build the new list by comparing the current nodes of `list1` and `list2`.
 * - At each step, attach the node with the smaller value to `cur->next`, then move the corresponding list forward.
 * - Continue this process until one of the lists becomes null.
 * - Finally, append the remaining part of the non-null list (if any) to `cur->next`.
 * - Return `dummy.next` which points to the head of the merged sorted list.
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        cur->next = (list1 != nullptr) ? list1 : list2;
        return dummy.next;
    }
};
