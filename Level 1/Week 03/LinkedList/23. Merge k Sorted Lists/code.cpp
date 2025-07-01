/**
 * Approach:
 * The task is to merge K sorted linked lists into one sorted linked list.
 * 
 * We use a **min-heap (priority queue)** to always extract the node with the smallest value across all lists.
 * 
 * Steps:
 * 1. Push the head node of each non-empty list into the min-heap.
 * 2. Pop the smallest node from the heap and add it to the result list.
 * 3. If the popped node has a next node, push that next node into the heap.
 * 4. Repeat until the heap is empty.
 * 
 * This ensures the final list is sorted by always taking the smallest current node.
 * 
 * Time Complexity: O(N log K), where N is the total number of nodes and K is the number of lists.
 * Space Complexity: O(K) for the heap.
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<>> pq;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            if (it.second->next)
                pq.push({it.second->next->val, it.second->next});
            temp->next = it.second;
            temp = temp->next;
        }

        return dummy->next;
    }
};
