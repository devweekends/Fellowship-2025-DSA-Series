/**
 * Approach:
 * The goal is to determine if a binary tree is height-balanced.
 * A binary tree is balanced if the height difference between 
 * the left and right subtrees of every node is no more than 1.
 *
 * Strategy:
 * - Use a helper function `checkheight` to recursively compute the height of subtrees.
 * - During the recursion, check if any subtree is unbalanced (height difference > 1).
 *   - If unbalanced, return -1 to propagate the failure up.
 *   - If balanced, return the height of the subtree.
 * - In the main function `isBalanced`, the tree is balanced if `checkheight` does not return -1.
 *
 * Time Complexity: O(n), where n is the number of nodes in the tree.
 *   - Each node is visited only once.
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
    int checkheight(TreeNode* root) {
        if (root == nullptr) return 0;

        int lh = checkheight(root->left);
        int rh = checkheight(root->right);

        if (lh == -1 || rh == -1) return -1;
        if (abs(lh - rh) > 1) return -1;

        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode* root) {
        return checkheight(root) != -1;
    }
};
