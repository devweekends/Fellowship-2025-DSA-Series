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
    // Helper function to check if two trees are identical
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        // If both nodes are null, trees are identical
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        }
        
        // If one node is null and other is not, trees are not identical
        if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        
        // Check if current nodes have same value and recursively check subtrees
        return (root1->val == root2->val) && 
               isSameTree(root1->left, root2->left) && 
               isSameTree(root1->right, root2->right);
    }
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // If subRoot is null, it's always a subtree (empty tree)
        if (subRoot == nullptr) {
            return true;
        }
        
        // If root is null but subRoot is not, it's not a subtree
        if (root == nullptr) {
            return false;
        }
        
        // Check if current root and subRoot form identical trees
        if (isSameTree(root, subRoot)) {
            return true;
        }
        
        // Recursively check if subRoot is a subtree of left or right child
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

/*
Time Complexity: O(m * n) where m is the number of nodes in root tree and n is the number of nodes in subRoot tree
Space Complexity: O(min(m, n)) due to recursion stack depth

Algorithm Explanation:
1. We use a two-step approach:
   - First, we check if the current root and subRoot form identical trees
   - If not, we recursively check if subRoot is a subtree of the left or right child

2. The isSameTree function:
   - Returns true if both nodes are null
   - Returns false if one node is null and other is not
   - Recursively checks if current nodes have same value and their subtrees are identical

3. The isSubtree function:
   - Handles edge cases (null checks)
   - Checks if current root and subRoot are identical
   - Recursively checks left and right subtrees

Example:
root = [3,4,5,1,2], subRoot = [4,1,2]

       3                   4
      / \                 / \
     4   5               1   2
    / \
   1   2

At node 3: isSameTree(3, 4) = false, so check left and right children
At node 4: isSameTree(4, 4) = true, so return true

The algorithm finds that the subtree starting at node 4 in the root tree
is identical to the subRoot tree.
*/
