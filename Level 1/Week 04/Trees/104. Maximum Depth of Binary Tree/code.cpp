/**
 * Approach:
 * The goal is to find the maximum depth (or height) of a binary tree.
 * 
 * This is done using recursion (Depth-First Search):
 * 1. If the current node is NULL, return 0 (base case).
 * 2. Recursively find the maximum depth of the left and right subtrees.
 * 3. Return the greater of the two depths plus 1 (for the current node).
 * 
 * Time Complexity: O(n), where n is the number of nodes in the tree (each node is visited once).
 * Space Complexity: O(h), where h is the height of the tree due to the recursion stack.
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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int lefth = maxDepth(root->left);
        int righth = maxDepth(root->right);
        return max(lefth, righth) + 1;
    }
};
