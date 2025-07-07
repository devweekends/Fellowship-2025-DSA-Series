/**
 * Approach:
 * This solution finds the **maximum path sum** in a binary tree.
 * 
 * Problem Definition:
 * A path is any sequence of nodes from some starting node to any node in the tree 
 * along the parent-child connections. The path must contain **at least one node**, 
 * and does **not need to go through the root**.

 * Strategy:
 * - Use a recursive helper function `maxPathSum1()` that:
 *   1. Calculates the maximum gain from the left and right subtrees.
 *   2. Ignores negative contributions by using `max(0, left/right subtree sum)`.
 *   3. Updates a reference variable `maxi` that stores the maximum path sum found so far.
 *   4. Returns the maximum gain that can be extended to the parent node 
 *      (either from left or right + root node).

 * - The overall maximum path may pass through the current node and both children,
 *   which is why we compute `lSum + rSum + root->val` to update the global max.

 * Time Complexity: O(n) – visits every node once.
 * Space Complexity: O(h) – recursion stack space, where h is the height of the tree.
 */

class Solution {
public:
    int maxPathSum1(TreeNode* root, int &maxi) {
        if (root == nullptr) return 0;

        int lSum = max(0, maxPathSum1(root->left, maxi));
        int rSum = max(0, maxPathSum1(root->right, maxi));
        maxi = max(maxi, lSum + rSum + root->val);
        return max(lSum, rSum) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathSum1(root, maxi);
        return maxi;
    }
};
