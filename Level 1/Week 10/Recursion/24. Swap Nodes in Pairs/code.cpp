/*
Problem: 24. Swap Nodes in Pairs

This is a classic linked list problem that can be solved elegantly using recursion.
Key insights:
1. We swap the first two nodes at each recursive call
2. We recursively process the remaining nodes
3. We need to handle edge cases (empty list, single node)
4. The recursive approach naturally handles the list structure

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
    ListNode* swapPairs(ListNode* head) {
        // Base case: if head is null or only one node remains
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Store the second node as it will become the new head
        ListNode* second = head->next;
        
        // Recursively swap the remaining nodes
        ListNode* remaining = swapPairs(second->next);
        
        // Swap the first two nodes
        second->next = head;
        head->next = remaining;
        
        // Return the new head (second node)
        return second;
    }
};
