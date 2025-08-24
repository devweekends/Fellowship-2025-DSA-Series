/*
Problem: 2. Add Two Numbers

This problem can be solved using recursion for digit-by-digit addition.
Key insights:
1. Base case: if both lists are null and no carry remains
2. Recursive case: add current digits and carry
3. Create a new node with the sum modulo 10
4. Recursively add the remaining digits with the carry
5. Connect the current node with the recursive result

Time Complexity: O(max(n, m)) - we visit each node once from both lists
Space Complexity: O(max(n, m)) - recursion stack depth
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbersHelper(l1, l2, 0);
    }
    
private:
    ListNode* addTwoNumbersHelper(ListNode* l1, ListNode* l2, int carry) {
        // Base case: if both lists are null and no carry remains
        if (l1 == nullptr && l2 == nullptr && carry == 0) {
            return nullptr;
        }
        
        // Get current digits (0 if list is null)
        int val1 = (l1 != nullptr) ? l1->val : 0;
        int val2 = (l2 != nullptr) ? l2->val : 0;
        
        // Calculate sum and new carry
        int sum = val1 + val2 + carry;
        int newCarry = sum / 10;
        int digit = sum % 10;
        
        // Create new node for current digit
        ListNode* newNode = new ListNode(digit);
        
        // Get next nodes for recursive call
        ListNode* next1 = (l1 != nullptr) ? l1->next : nullptr;
        ListNode* next2 = (l2 != nullptr) ? l2->next : nullptr;
        
        // Recursively add the remaining digits
        newNode->next = addTwoNumbersHelper(next1, next2, newCarry);
        
        return newNode;
    }
};
