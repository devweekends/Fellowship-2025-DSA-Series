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
    int preorderIndex = 0;
    unordered_map<int, int> inorderMap;
    
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        // Base case: no elements to construct
        if (left > right) {
            return nullptr;
        }
        
        // Get the root value from preorder (first element)
        int rootValue = preorder[preorderIndex];
        TreeNode* root = new TreeNode(rootValue);
        preorderIndex++;
        
        // Find the position of root in inorder traversal
        int inorderIndex = inorderMap[rootValue];
        
        // Recursively construct left subtree
        // Left subtree: elements before root in inorder
        root->left = buildTreeHelper(preorder, inorder, left, inorderIndex - 1);
        
        // Recursively construct right subtree
        // Right subtree: elements after root in inorder
        root->right = buildTreeHelper(preorder, inorder, inorderIndex + 1, right);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Create a hash map for O(1) lookup of inorder positions
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }
        
        return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1);
    }
};

/*
Time Complexity: O(n) where n is the number of nodes
Space Complexity: O(n) for the hash map and recursion stack

Algorithm Explanation:
1. Preorder traversal: Root -> Left -> Right
2. Inorder traversal: Left -> Root -> Right
3. Key insight: First element in preorder is always the root
4. In inorder, all elements before root belong to left subtree
5. All elements after root belong to right subtree

Steps:
1. Take first element from preorder as root
2. Find root's position in inorder
3. Left subtree: elements before root in inorder
4. Right subtree: elements after root in inorder
5. Recursively construct left and right subtrees

Example:
preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]

Step 1: Root = 3 (first in preorder)
         Inorder: [9,3,15,20,7]
         Left subtree: [9] (before 3)
         Right subtree: [15,20,7] (after 3)

Step 2: Left subtree
         Root = 9 (next in preorder)
         Inorder: [9]
         No left/right subtrees

Step 3: Right subtree
         Root = 20 (next in preorder)
         Inorder: [15,20,7]
         Left subtree: [15] (before 20)
         Right subtree: [7] (after 20)

Final tree:
       3
      / \
     9  20
        / \
       15  7
*/
