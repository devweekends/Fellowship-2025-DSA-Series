/**
 * Approach:
 * The goal is to find the minimum depth of a binary tree.
 * Minimum depth is defined as the number of nodes along the shortest path 
 * from the root node down to the nearest leaf node.
 *
 * Steps:
 * 1. If the current node is NULL, return 0 (empty tree).
 * 2. If the left child is NULL, recursively compute the minimum depth of the right subtree.
 * 3. If the right child is NULL, recursively compute the minimum depth of the left subtree.
 * 4. If both children are present, take the minimum of both subtrees and add 1 (for the current node).
 *
 * Note: We handle the cases where one subtree is NULL separately to ensure we don't consider a NULL path.
 *
 * Time Complexity: O(n), where n is the number of nodes (in the worst case, all nodes are visited).
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
    int minDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL) {
            return 1 + minDepth(root->right);
        }
        if (root->right == NULL) {
            return 1 + minDepth(root->left);
        }
        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};
