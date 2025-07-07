/**
 * Approach:
 * This solution finds the k-th smallest element in a Binary Search Tree (BST)
 * using **inorder traversal**. Inorder traversal of a BST gives nodes in ascending order.
 * 
 * Strategy:
 * - Perform an inorder traversal of the BST.
 * - Keep a counter to track how many nodes have been visited.
 * - When the counter reaches `k`, record the current node's value as the result.
 * - To optimize, stop further traversal once the k-th element is found.
 * 
 * Time Complexity: O(H + k), where H is the height of the tree.
 *   - Best case: balanced tree → O(log n + k)
 *   - Worst case: skewed tree → O(n)
 * Space Complexity: O(H) for the recursive call stack.
 */

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int cnt = 0;
    int result = -1;

    void inorder(TreeNode* root, int k){
        if(root == NULL || result != -1){
            return;
        }

        inorder(root->left, k);
        cnt++;
        if(cnt == k){
            result = root->val;
            return;
        }
        inorder(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return result;
    }
};
