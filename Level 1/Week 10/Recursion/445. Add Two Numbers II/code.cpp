/*
Problem: 445. Add Two Numbers II

This problem is more complex than Add Two Numbers I because digits are in forward order.
Key insights:
1. First, we need to reverse both lists to work with least significant digits first
2. Use the recursive approach from Add Two Numbers I
3. Reverse the result back to get the correct order
4. Handle the carry propagation from least to most significant digits

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
        // Reverse both lists to work with least significant digits first
        ListNode* reversedL1 = reverseList(l1);
        ListNode* reversedL2 = reverseList(l2);
        
        // Add the reversed lists
        ListNode* result = addTwoNumbersHelper(reversedL1, reversedL2, 0);
        
        // Reverse the result back to get the correct order
        return reverseList(result);
    }
    
private:
    // Helper function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* reversedRest = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return reversedRest;
    }
    
    // Helper function to add two reversed lists
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
