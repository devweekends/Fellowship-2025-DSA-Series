/*
Problem: 23. Merge k Sorted Lists

This is a complex problem that uses divide and conquer with recursion.
Key insights:
1. Base case: if there are 0 or 1 lists, return the list or empty
2. Recursive case: divide the lists into two halves
3. Recursively merge each half
4. Merge the two merged halves using the two-list merge approach
5. Return the final merged list

Time Complexity: O(N log k) where N is total number of nodes
Space Complexity: O(log k) - recursion stack depth
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Base case: if no lists
        if (lists.empty()) {
            return nullptr;
        }
        
        // Base case: if only one list
        if (lists.size() == 1) {
            return lists[0];
        }
        
        // Recursive case: divide and conquer
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
    
private:
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {
        // Base case: if only one list
        if (start == end) {
            return lists[start];
        }
        
        // Base case: if two lists
        if (start + 1 == end) {
            return mergeTwoLists(lists[start], lists[end]);
        }
        
        // Divide: find the middle
        int mid = start + (end - start) / 2;
        
        // Conquer: recursively merge each half
        ListNode* left = mergeKListsHelper(lists, start, mid);
        ListNode* right = mergeKListsHelper(lists, mid + 1, end);
        
        // Combine: merge the two halves
        return mergeTwoLists(left, right);
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
