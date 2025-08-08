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
    int count = 0;
    int result = -1;
    
    // Inorder traversal to find kth smallest element
    void inorder(TreeNode* root, int k) {
        if (root == nullptr || result != -1) {
            return;
        }
        
        // Traverse left subtree first (smaller values)
        inorder(root->left, k);
        
        // Process current node
        count++;
        if (count == k) {
            result = root->val;
            return;
        }
        
        // Traverse right subtree (larger values)
        inorder(root->right, k);
    }
    
public:
    int kthSmallest(TreeNode* root, int k) {
        count = 0;
        result = -1;
        inorder(root, k);
        return result;
    }
};

/*
Time Complexity: O(k) in worst case, O(n) in average case
Space Complexity: O(h) where h is the height of the tree (due to recursion stack)

Algorithm Explanation:
1. We use inorder traversal which visits nodes in ascending order in a BST
2. Inorder traversal: left subtree -> current node -> right subtree
3. We keep track of the count of nodes visited
4. When count equals k, we've found the kth smallest element
5. We can stop early once we find the kth element

Key insights:
- Inorder traversal of BST gives elements in sorted order
- Left subtree contains smaller elements
- Right subtree contains larger elements
- We visit nodes in ascending order: left -> root -> right

Example:
       3
      / \
     1   4
      \
       2

Inorder traversal: 1 -> 2 -> 3 -> 4
For k = 1: return 1 (1st smallest)
For k = 2: return 2 (2nd smallest)
For k = 3: return 3 (3rd smallest)
For k = 4: return 4 (4th smallest)

Alternative approaches:
1. Store inorder traversal in array and return arr[k-1]
2. Use iterative inorder traversal with stack
3. Use Morris traversal for O(1) space complexity
*/
