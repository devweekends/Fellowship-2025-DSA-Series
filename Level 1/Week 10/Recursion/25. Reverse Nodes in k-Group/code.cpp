/*
Problem: 25. Reverse Nodes in k-Group

This is a complex linked list problem that requires recursion and careful pointer manipulation.
Key insights:
1. We need to check if there are k nodes remaining before reversing
2. We reverse the first k nodes using iterative approach
3. We recursively process the remaining nodes
4. We connect the reversed group with the result of recursive call
5. We handle edge cases where remaining nodes are less than k

Time Complexity: O(n) - we visit each node once
Space Complexity: O(n/k) - recursion stack depth for each group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Check if there are k nodes remaining
        ListNode* current = head;
        int count = 0;
        while (current != nullptr && count < k) {
            current = current->next;
            count++;
        }
        
        // If we have k nodes, reverse them
        if (count == k) {
            // Reverse the first k nodes
            ListNode* reversedHead = reverseFirstK(head, k);
            
            // Recursively reverse the remaining nodes
            ListNode* remaining = reverseKGroup(current, k);
            
            // Connect the reversed group with the remaining result
            head->next = remaining;
            
            return reversedHead;
        }
        
        // If less than k nodes remain, return as is
        return head;
    }
    
private:
    // Helper function to reverse the first k nodes
    ListNode* reverseFirstK(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        
        for (int i = 0; i < k; i++) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        return prev;
    }
};
