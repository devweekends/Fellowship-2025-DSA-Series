/**
 * Approach:
 * The goal is to invert a binary tree, meaning swap every left and right subtree recursively.
 * This is done using a Depth-First Search (DFS) approach:
 * 
 * 1. Traverse the tree recursively.
 * 2. At each node, recursively invert the left and right subtrees.
 * 3. Swap the left and right pointers of the current node.
 * 4. Return the root after the entire tree has been inverted.
 * 
 * Time Complexity: O(n), where n is the number of nodes in the tree.
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
    TreeNode* invert(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* left = invert(root->left);
        TreeNode* right = invert(root->right);
        root->left = right;
        root->right = left;
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        return invert(root); 
    }
};
