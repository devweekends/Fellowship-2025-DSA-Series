/*
Problem: 21. Merge Two Sorted Lists

This is a classic recursion problem for merging two sorted linked lists.
Key insights:
1. Base case: if one list is empty, return the other list
2. Recursive case: compare the heads of both lists
3. Choose the smaller head and recursively merge the rest
4. Connect the chosen head with the result of recursive merge
5. Return the merged list

Time Complexity: O(n + m) - we visit each node once from both lists
Space Complexity: O(n + m) - recursion stack depth
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Base case: if one list is empty, return the other
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        
        // Compare the heads of both lists
        if (list1->val <= list2->val) {
            // Choose list1's head and recursively merge the rest
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            // Choose list2's head and recursively merge the rest
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
