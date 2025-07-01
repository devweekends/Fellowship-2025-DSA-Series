/**
 * Approach:
 * The goal is to create a deep copy of a linked list where each node has two pointers:
 * `next` and `random`, which can point to any node or be null.
 *
 * We use a **three-pass approach** with constant space (O(1) extra space):
 * 
 * 1. **First Pass – Clone and interleave nodes**:
 *    - For each node in the original list, create a copy and insert it just after the original node.
 *    - Example: A → B → C becomes A → A' → B → B' → C → C'
 *
 * 2. **Second Pass – Assign random pointers**:
 *    - For each copied node, set its `random` pointer using the original node's random pointer.
 *    - `copy->random = original->random->next`
 *
 * 3. **Third Pass – Separate the two lists**:
 *    - Detach the original and the copied nodes to form two separate lists.
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1) (no additional hash maps used)
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
         
        // Step 1: Interleave copied nodes with original nodes
        Node* temp = head;
        while (temp != nullptr) {
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }

        // Step 2: Assign random pointers to copied nodes
        temp = head;
        while (temp != nullptr) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        // Step 3: Separate the original and copied lists
        Node* dummy = new Node(0);
        Node* res = dummy;
        temp = head;

        while (temp != nullptr) {
            Node* copyNode = temp->next;
            res->next = copyNode;
            temp->next = copyNode->next;

            res = res->next;
            temp = temp->next;
        }

        return dummy->next;
    }
};
