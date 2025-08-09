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
private:
    int maxSum = INT_MIN;
    
    // Returns the maximum path sum that can be extended from current node
    int maxPathSumHelper(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        // Get maximum path sum from left and right subtrees
        // If negative, we don't include them (take 0 instead)
        int leftSum = max(0, maxPathSumHelper(root->left));
        int rightSum = max(0, maxPathSumHelper(root->right));
        
        // Calculate the maximum path sum that includes current node
        // This can be: current node + left path + right path
        int currentSum = root->val + leftSum + rightSum;
        maxSum = max(maxSum, currentSum);
        
        // Return the maximum path sum that can be extended from current node
        // This is used by parent nodes to calculate their path sums
        return root->val + max(leftSum, rightSum);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxPathSumHelper(root);
        return maxSum;
    }
};

/*
Time Complexity: O(n) where n is the number of nodes in the tree
Space Complexity: O(h) where h is the height of the tree (due to recursion stack)

Algorithm Explanation:
1. We use DFS to traverse the tree
2. For each node, we calculate:
   - Maximum path sum from left subtree (if positive, else 0)
   - Maximum path sum from right subtree (if positive, else 0)
   - Maximum path sum that includes current node and both subtrees
3. We update the global maximum if current path sum is greater
4. We return the maximum path sum that can be extended from current node

Key insights:
- A path can go through any node and can include both left and right subtrees
- If a subtree contributes negative sum, we don't include it (take 0)
- The maximum path sum can be anywhere in the tree, not necessarily through root

Example:
       -10
      /   \
     9    20
         /  \
        15   7

Processing:
- Node 15: leftSum = 0, rightSum = 0, currentSum = 15, maxSum = 15
- Node 7: leftSum = 0, rightSum = 0, currentSum = 7, maxSum = 15
- Node 20: leftSum = 15, rightSum = 7, currentSum = 20 + 15 + 7 = 42, maxSum = 42
- Node 9: leftSum = 0, rightSum = 0, currentSum = 9, maxSum = 42
- Node -10: leftSum = 9, rightSum = 42, currentSum = -10 + 9 + 42 = 41, maxSum = 42

Final result: 42 (path: 15 -> 20 -> 7)

The algorithm finds the maximum path sum by considering all possible paths
through each node and updating the global maximum accordingly.
*/
