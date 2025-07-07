/**
 * Approach:
 * This solution checks whether a given binary tree is a **valid Binary Search Tree (BST)**.
 * 
 * Key Properties of a BST:
 * - For every node, all values in the **left subtree** must be **less than** the node's value.
 * - All values in the **right subtree** must be **greater than** the node's value.
 * - This condition must hold **recursively** for all nodes.

 * Strategy:
 * - Use a helper function `validate` that recursively checks if each node's value lies
 *   within a valid range `(minVal, maxVal)`.
 * - For the left child, the `maxVal` becomes the current node's value.
 * - For the right child, the `minVal` becomes the current node's value.
 * - Start with the full range of values: `(-∞, ∞)` using `LONG_MIN` and `LONG_MAX`.

 * Time Complexity: O(n), where n is the number of nodes in the tree.
 * Space Complexity: O(h), where h is the height of the tree (due to recursion stack).
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
    bool validate(TreeNode* root , long minVal , long maxVal){
        if (root == NULL) return true;

        if (root->val <= minVal || root->val >= maxVal)
            return false;

        return validate(root->left, minVal, root->val) &&
               validate(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        return validate(root, LONG_MIN, LONG_MAX);
    }
};
