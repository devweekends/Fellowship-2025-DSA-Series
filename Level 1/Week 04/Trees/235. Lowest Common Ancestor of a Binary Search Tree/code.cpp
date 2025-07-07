/**
 * Approach:
 * This solution finds the **Lowest Common Ancestor (LCA)** of two nodes `p` and `q` in a binary tree (not necessarily a BST).
 *
 * Strategy:
 * - Perform a post-order traversal (DFS) from the root.
 * - If the current node matches either `p` or `q`, return that node.
 * - Recursively find LCA in the left and right subtrees.
 *   - If both left and right calls return non-null, it means `p` and `q` are found in different subtrees,
 *     so the current node is their LCA.
 *   - If only one subtree returns non-null, that means both `p` and `q` are in that subtree,
 *     so propagate the result upwards.
 *   - If both return null, return null.
 *
 * Time Complexity: O(n), where n is the number of nodes in the tree.
 * Space Complexity: O(h), where h is the height of the tree (due to recursion stack).
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        if (root->val == p->val || root->val == q->val) {
            return root;
        }

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if (leftLCA && rightLCA) {
            return root;
        } else if (rightLCA != NULL) {
            return rightLCA;
        } else {
            return leftLCA;
        }
    }
};
