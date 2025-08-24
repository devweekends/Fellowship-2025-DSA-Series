/*
Problem: 148. Sort List

This problem can be solved using merge sort with recursion.
Key insights:
1. Base case: if head is null or only one node remains
2. Recursive case: find the middle of the list
3. Recursively sort the left and right halves
4. Merge the two sorted halves
5. Return the merged sorted list

Time Complexity: O(n log n) - merge sort complexity
Space Complexity: O(log n) - recursion stack depth
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
    ListNode* sortList(ListNode* head) {
        // Base case: if head is null or only one node remains
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        // Find the middle of the list
        ListNode* middle = findMiddle(head);
        ListNode* secondHalf = middle->next;
        middle->next = nullptr;  // Split the list
        
        // Recursively sort each half
        ListNode* left = sortList(head);
        ListNode* right = sortList(secondHalf);
        
        // Merge the two sorted halves
        return mergeTwoLists(left, right);
    }
    
private:
    // Helper function to find the middle of the list
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    // Helper function to merge two sorted lists
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
