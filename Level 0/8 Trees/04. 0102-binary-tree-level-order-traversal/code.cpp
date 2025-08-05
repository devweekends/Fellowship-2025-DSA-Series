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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        // If tree is empty, return empty result
        if (root == nullptr) {
            return result;
        }
        
        // Use queue for BFS traversal
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;
            
            // Process all nodes at current level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // Add current node's value to current level
                currentLevel.push_back(node->val);
                
                // Add left child to queue if exists
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                
                // Add right child to queue if exists
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            // Add current level to result
            result.push_back(currentLevel);
        }
        
        return result;
    }
};

/*
Time Complexity: O(n) where n is the number of nodes in the tree
Space Complexity: O(w) where w is the maximum width of the tree (worst case O(n))

Algorithm Explanation:
1. We use Breadth-First Search (BFS) with a queue to traverse the tree level by level
2. For each level:
   - Get the number of nodes at current level (queue size)
   - Process all nodes at current level
   - Add their values to current level vector
   - Add their children to queue for next level
   - Add current level to result

3. The queue ensures that nodes are processed in the correct order:
   - Level 0: root
   - Level 1: all children of root
   - Level 2: all children of level 1 nodes
   - And so on...

Example:
       3
      / \
     9  20
        / \
       15  7

Queue state and processing:
1. Queue: [3], Level: 0, Result: [[3]]
2. Queue: [9, 20], Level: 1, Result: [[3], [9, 20]]
3. Queue: [15, 7], Level: 2, Result: [[3], [9, 20], [15, 7]]
4. Queue: [], Done

Final result: [[3], [9, 20], [15, 7]]
*/
