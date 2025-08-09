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
    // DFS helper function to count good nodes
    void dfs(TreeNode* root, int maxSoFar, int& count) {
        if (root == nullptr) {
            return;
        }
        
        // If current node's value is >= maxSoFar, it's a good node
        if (root->val >= maxSoFar) {
            count++;
        }
        
        // Update maxSoFar for children
        int newMax = max(maxSoFar, root->val);
        
        // Recursively check left and right subtrees
        dfs(root->left, newMax, count);
        dfs(root->right, newMax, count);
    }
    
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        dfs(root, root->val, count); // Start with root's value as maxSoFar
        return count;
    }
};

/*
Time Complexity: O(n) where n is the number of nodes in the tree
Space Complexity: O(h) where h is the height of the tree (due to recursion stack)

Algorithm Explanation:
1. We use DFS to traverse the tree
2. For each node, we track the maximum value seen so far in the path from root
3. A node is "good" if its value is >= the maximum value in the path from root to it
4. We pass the current maximum value to child nodes
5. If a node's value >= current maximum, we increment the count

Key insights:
- Root is always a good node (no nodes above it)
- For any node, if its value >= max value in path from root, it's good
- We need to track the maximum value in the path, not just the parent's value

Example:
       3
      / \
     1   4
    /   / \
   3   1   5

Path analysis:
- Root (3): maxSoFar = 3, 3 >= 3, good node, count = 1
- Left child (1): maxSoFar = 3, 1 < 3, not good, count = 1
- Left-left child (3): maxSoFar = 3, 3 >= 3, good node, count = 2
- Right child (4): maxSoFar = 4, 4 >= 4, good node, count = 3
- Right-left child (1): maxSoFar = 4, 1 < 4, not good, count = 3
- Right-right child (5): maxSoFar = 5, 5 >= 5, good node, count = 4

Final result: 4 good nodes (3, 3, 4, 5)
*/
