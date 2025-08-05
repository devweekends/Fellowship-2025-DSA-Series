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
    // Helper function to check if tree is valid BST within given range
    bool isValidBSTHelper(TreeNode* root, long long minVal, long long maxVal) {
        if (root == nullptr) {
            return true;
        }
        
        // Check if current node's value is within the valid range
        if (root->val <= minVal || root->val >= maxVal) {
            return false;
        }
        
        // Recursively check left subtree (must be < current node)
        // and right subtree (must be > current node)
        return isValidBSTHelper(root->left, minVal, root->val) &&
               isValidBSTHelper(root->right, root->val, maxVal);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        // Use long long to handle edge cases with INT_MIN and INT_MAX
        return isValidBSTHelper(root, LLONG_MIN, LLONG_MAX);
    }
};

/*
Time Complexity: O(n) where n is the number of nodes in the tree
Space Complexity: O(h) where h is the height of the tree (due to recursion stack)

Algorithm Explanation:
1. We use DFS with range checking for each node
2. For each node, we maintain a valid range [minVal, maxVal]
3. Left child must be < current node, so range becomes [minVal, current_val]
4. Right child must be > current node, so range becomes [current_val, maxVal]
5. If any node's value is outside its valid range, the tree is not a BST

Key insights:
- Each node must be within a specific range based on its ancestors
- Left subtree values must be < current node
- Right subtree values must be > current node
- We use long long to handle edge cases with INT_MIN/INT_MAX

Example:
       5
      / \
     1   4
        / \
       3   6

Validation process:
- Root (5): range [LLONG_MIN, LLONG_MAX], 5 is valid
- Left child (1): range [LLONG_MIN, 5], 1 is valid
- Right child (4): range [5, LLONG_MAX], 4 < 5, INVALID!

The tree is invalid because 4 is less than its parent 5.

Alternative approach using inorder traversal:
- Inorder traversal of BST gives sorted sequence
- If inorder traversal is not sorted, tree is not BST
*/
