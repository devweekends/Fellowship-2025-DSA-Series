/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
private:
    // Helper function to serialize tree using preorder traversal
    void serializeHelper(TreeNode* root, string& result) {
        if (root == nullptr) {
            result += "null,";
            return;
        }
        
        // Add current node's value
        result += to_string(root->val) + ",";
        
        // Recursively serialize left and right subtrees
        serializeHelper(root->left, result);
        serializeHelper(root->right, result);
    }
    
    // Helper function to deserialize tree using preorder traversal
    TreeNode* deserializeHelper(queue<string>& data) {
        if (data.empty()) {
            return nullptr;
        }
        
        string val = data.front();
        data.pop();
        
        if (val == "null") {
            return nullptr;
        }
        
        // Create current node
        TreeNode* root = new TreeNode(stoi(val));
        
        // Recursively deserialize left and right subtrees
        root->left = deserializeHelper(data);
        root->right = deserializeHelper(data);
        
        return root;
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";
        serializeHelper(root, result);
        return result;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        
        // Parse the string into a queue of values
        queue<string> dataQueue;
        stringstream ss(data);
        string item;
        
        while (getline(ss, item, ',')) {
            dataQueue.push(item);
        }
        
        return deserializeHelper(dataQueue);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

/*
Time Complexity: O(n) for both serialize and deserialize
Space Complexity: O(n) for both serialize and deserialize

Algorithm Explanation:
1. Serialization (Tree to String):
   - Use preorder traversal (Root -> Left -> Right)
   - For each node, add its value to the string
   - For null nodes, add "null"
   - Separate values with commas
   - This creates a unique representation of the tree

2. Deserialization (String to Tree):
   - Parse the string into a queue of values
   - Use preorder traversal to reconstruct the tree
   - For each value, create a node and recursively build subtrees
   - "null" values represent null pointers

Key insights:
- Preorder traversal ensures we can reconstruct the tree uniquely
- The order of nodes in serialized string matches preorder traversal
- We can use any traversal order, but preorder is most straightforward

Example:
       1
      / \
     2   3
        / \
       4   5

Serialization process:
1. Root (1): "1,"
2. Left child (2): "1,2,"
3. Left child of 2 (null): "1,2,null,"
4. Right child of 2 (null): "1,2,null,null,"
5. Right child (3): "1,2,null,null,3,"
6. Left child of 3 (4): "1,2,null,null,3,4,"
7. Left child of 4 (null): "1,2,null,null,3,4,null,"
8. Right child of 4 (null): "1,2,null,null,3,4,null,null,"
9. Right child of 3 (5): "1,2,null,null,3,4,null,null,5,"
10. Left child of 5 (null): "1,2,null,null,3,4,null,null,5,null,"
11. Right child of 5 (null): "1,2,null,null,3,4,null,null,5,null,null,"

Final result: "1,2,null,null,3,4,null,null,5,null,null,"

Deserialization process:
- Read values in order and reconstruct the tree using preorder traversal
- Each "null" represents a null pointer
- The tree is reconstructed exactly as it was
*/
