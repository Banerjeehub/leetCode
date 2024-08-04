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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string result = "";

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            auto top = q.front();
            q.pop();

            if(top == NULL) result += "#,";
            else
            {
                result += to_string(top->val) + ",";
                q.push(top->left);
                q.push(top->right);
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        
        stringstream dataStream(data);
        string value;
        getline(dataStream, value, ',');
        
        TreeNode* root = new TreeNode(stoi(value));
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        
        while (!nodeQueue.empty()) {
            TreeNode* currentNode = nodeQueue.front();
            nodeQueue.pop();
            
            // Process left child
            getline(dataStream, value, ',');
            if (value == "#") {
                currentNode->left = NULL;
            } else {
                currentNode->left = new TreeNode(stoi(value));
                nodeQueue.push(currentNode->left);
            }
            
            // Process right child
            getline(dataStream, value, ',');
            if (value == "#") {
                currentNode->right = NULL;
            } else {
                currentNode->right = new TreeNode(stoi(value));
                nodeQueue.push(currentNode->right);
            }
        }
        
        return root;
    }
};

// Example usage:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));