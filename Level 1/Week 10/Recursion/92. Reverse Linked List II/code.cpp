/*
Problem: 92. Reverse Linked List II

This problem requires reversing a specific range of nodes in a linked list using recursion.
Key insights:
1. We need to track the current position as we traverse the list
2. When we reach the left position, we start reversing
3. We reverse nodes from left to right
4. We connect the reversed portion with the rest of the list
5. We handle edge cases where left equals right

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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // If left equals right, no reversal needed
        if (left == right) {
            return head;
        }
        
        // Start recursion from position 1
        return reverseHelper(head, 1, left, right);
    }
    
private:
    ListNode* reverseHelper(ListNode* head, int pos, int left, int right) {
        // Base case: if we've reached the left position
        if (pos == left) {
            return reverseRange(head, right - left + 1);
        }
        
        // Recursive case: move forward until we reach left position
        head->next = reverseHelper(head->next, pos + 1, left, right);
        return head;
    }
    
    // Helper function to reverse a range of nodes
    ListNode* reverseRange(ListNode* head, int count) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        ListNode* tail = head;  // Store the tail to connect with remaining list
        
        for (int i = 0; i < count; i++) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        // Connect the reversed portion with the remaining list
        tail->next = current;
        
        return prev;
    }
};
