/*
Problem: 206. Reverse Linked List

This is a classic recursion problem for reversing a linked list.
Key insights:
1. Base case: if head is null or only one node remains
2. Recursive case: reverse the rest of the list
3. Make the current node point to the reversed list
4. Return the new head (which is the last node of original list)
5. The recursive approach naturally handles the reversal by working backwards

Time Complexity: O(n) - we visit each node once
Space Complexity: O(n) - recursion stack depth
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
    ListNode* reverseList(ListNode* head) {
        // Base case: if head is null or only one node remains
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Recursively reverse the rest of the list
        ListNode* reversedRest = reverseList(head->next);
        
        // Make the current node point to the reversed list
        head->next->next = head;
        head->next = nullptr;
        
        // Return the new head (which is the last node of original list)
        return reversedRest;
    }
};
