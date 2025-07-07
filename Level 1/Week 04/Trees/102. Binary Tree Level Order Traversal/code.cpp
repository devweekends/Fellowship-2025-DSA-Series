/**
 * Approach:
 * This solution performs a **level-order traversal** (Breadth-First Search) of a binary tree.
 * Each level of the tree is visited from left to right and stored as a separate sub-array.
 *
 * Strategy:
 * - Use a queue to keep track of nodes at each level.
 * - For each level:
 *   - Determine the number of nodes (`size`) currently in the queue.
 *   - Process each node, adding its children (left and right) to the queue.
 *   - Store the values of the current level in a temporary vector and append it to the result.
 *
 * Time Complexity: O(n), where n is the number of nodes in the tree.
 * Space Complexity: O(n), for storing the result and the queue.
 */

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
   void levelOrder1(TreeNode* root , vector<vector<int>> &arr){
      if(root == nullptr) return;

      queue<TreeNode*> q;
      q.push(root);
      while(!q.empty()){
          int size = q.size();
          vector<int> level;
          for(int i = 0; i < size; i++){
              TreeNode *node = q.front();
              q.pop();
              if(node->left != NULL)
                  q.push(node->left);
              if(node->right != NULL)
                  q.push(node->right);
              level.push_back(node->val);
          }
          arr.push_back(level);
      }
   }

   vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> arr;
       levelOrder1(root, arr);
       return arr;
   }
};
