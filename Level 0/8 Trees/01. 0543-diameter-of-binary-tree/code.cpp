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
    int maxDiameter = 0;
    
    // Helper function to calculate the height of a subtree
    // and update the maximum diameter found so far
    int calculateHeight(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        // Recursively calculate heights of left and right subtrees
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);
        
        // Update the maximum diameter
        // Diameter = leftHeight + rightHeight (number of edges between leftmost and rightmost nodes)
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
        
        // Return the height of current subtree (max of left or right + 1 for current node)
        return max(leftHeight, rightHeight) + 1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        // Reset the maximum diameter
        maxDiameter = 0;
        
        // Calculate heights and update diameter
        calculateHeight(root);
        
        return maxDiameter;
    }
};

/*
Time Complexity: O(n) where n is the number of nodes in the tree
Space Complexity: O(h) where h is the height of the tree (due to recursion stack)

Algorithm Explanation:
1. The diameter of a binary tree is the longest path between any two nodes
2. This path may or may not pass through the root
3. For any node, the diameter through that node = left subtree height + right subtree height
4. We use a DFS approach to calculate heights of all subtrees
5. While calculating heights, we also keep track of the maximum diameter found
6. The height of a node = max(left subtree height, right subtree height) + 1
7. The diameter through a node = left subtree height + right subtree height (no +1 because we count edges, not nodes)

Example:
       1
      / \
     2   3
    / \
   4   5

For node 1: leftHeight = 2, rightHeight = 1, diameter = 2 + 1 = 3
For node 2: leftHeight = 1, rightHeight = 1, diameter = 1 + 1 = 2
For node 3: leftHeight = 0, rightHeight = 0, diameter = 0 + 0 = 0
For node 4: leftHeight = 0, rightHeight = 0, diameter = 0 + 0 = 0
For node 5: leftHeight = 0, rightHeight = 0, diameter = 0 + 0 = 0

Maximum diameter = 3 (path from 4 to 3 via 2 and 1)
*/
