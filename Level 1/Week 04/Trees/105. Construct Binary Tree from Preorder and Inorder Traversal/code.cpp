/**
 * Approach:
 * This solution reconstructs a **binary tree** from given preorder and inorder traversal arrays.
 * 
 * Key Observations:
 * - The **first** element of the preorder array is always the **root** of the tree/subtree.
 * - In the inorder array, elements to the **left** of the root belong to the **left subtree**,
 *   and elements to the **right** belong to the **right subtree**.

 * Strategy:
 * 1. Use a helper function with parameters to control the range (`left` to `right`) of the inorder array.
 * 2. Maintain a `preIdx` to keep track of the current root node in preorder traversal.
 * 3. For each recursive call:
 *    - Create the root node using `preorder[preIdx]`.
 *    - Find that root's index in the inorder array (`inIdx`).
 *    - Recursively build the left subtree from `left` to `inIdx - 1`.
 *    - Recursively build the right subtree from `inIdx + 1` to `right`.
 * 
 * Time Complexity: O(n²) in worst case due to the linear `search()` in inorder array.
 *   - This can be improved to O(n) using a hashmap for value-to-index lookups.
 * Space Complexity: O(n) for recursion stack and tree construction.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx,
                     int left, int right) {
        if (left > right) return NULL;

        TreeNode* root = new TreeNode(preorder[preIdx]);
        int inIdx = search(inorder, left, right, preorder[preIdx]);
        preIdx++;

        root->left = helper(preorder, inorder, preIdx, left, inIdx - 1);
        root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};
