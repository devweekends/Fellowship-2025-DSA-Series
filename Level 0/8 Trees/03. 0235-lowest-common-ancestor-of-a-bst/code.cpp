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
        // If root is null, return null
        if (root == nullptr) {
            return nullptr;
        }
        
        // If both p and q are less than root, LCA is in left subtree
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        
        // If both p and q are greater than root, LCA is in right subtree
        if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        
        // If p and q are on different sides of root, or one of them equals root,
        // then root is the LCA
        return root;
    }
};

/*
Time Complexity: O(h) where h is the height of the BST
Space Complexity: O(h) due to recursion stack

Algorithm Explanation:
1. We use the BST property: left subtree contains nodes with values < root, 
   right subtree contains nodes with values > root

2. The algorithm works as follows:
   - If both p and q are less than root, LCA must be in the left subtree
   - If both p and q are greater than root, LCA must be in the right subtree
   - If p and q are on different sides of root, or one equals root, then root is the LCA

3. This works because:
   - In a BST, the LCA is the first node where p and q diverge
   - If both nodes are on the same side, we continue searching in that direction
   - When they diverge (one on left, one on right), we've found the LCA

Example:
       6
      / \
     2   8
    / \ / \
   0  4 7  9
      / \
     3   5

For p=2, q=8:
- At node 6: 2 < 6 and 8 > 6, so they diverge here
- Return 6 (LCA)

For p=2, q=4:
- At node 6: 2 < 6 and 4 < 6, so go left
- At node 2: 2 = 2 and 4 > 2, so they diverge here
- Return 2 (LCA)

For p=2, q=2:
- At node 6: 2 < 6, so go left
- At node 2: 2 = 2, so return 2 (node is descendant of itself)
*/
