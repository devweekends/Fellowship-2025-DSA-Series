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
    // DFS approach: traverse right first, then left
    void dfs(TreeNode* root, int depth, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        
        // If this is the first node we've seen at this depth,
        // add it to the result (right side view)
        if (depth == result.size()) {
            result.push_back(root->val);
        }
        
        // Traverse right first, then left
        // This ensures we see the rightmost node at each level first
        dfs(root->right, depth + 1, result);
        dfs(root->left, depth + 1, result);
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        dfs(root, 0, result);
        return result;
    }
};

/*
Time Complexity: O(n) where n is the number of nodes in the tree
Space Complexity: O(h) where h is the height of the tree (due to recursion stack)

Algorithm Explanation:
1. We use a DFS approach with a modified traversal order
2. Key insight: The right side view consists of the rightmost node at each level
3. We traverse right child first, then left child
4. For each level, the first node we encounter is the rightmost node
5. We use the depth to track which level we're at
6. If depth equals result.size(), it means this is the first node at this level

Alternative BFS approach:
- Use level order traversal
- For each level, add the last node (rightmost) to the result

Example:
       1
      / \
     2   3
      \   \
       5   4

DFS traversal order: 1 -> 3 -> 4 -> 2 -> 5
At depth 0: result.size() = 0, add 1, result = [1]
At depth 1: result.size() = 1, add 3, result = [1, 3]
At depth 2: result.size() = 2, add 4, result = [1, 3, 4]
At depth 2: result.size() = 3, skip 2 (already have depth 2)
At depth 3: result.size() = 3, skip 5 (already have depth 2)

Final result: [1, 3, 4]

The right side view shows:
- Level 0: node 1
- Level 1: node 3 (rightmost at this level)
- Level 2: node 4 (rightmost at this level)
*/
