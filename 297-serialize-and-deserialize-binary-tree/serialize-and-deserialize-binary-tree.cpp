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
        if (!root)
            return "";
        string res = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            if (top == nullptr)
                res += "#,";
            else {
                res += to_string(top->val) + ",";
                q.push(top->left);
                q.push(top->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if (data.size() == 0)
            return nullptr;
        stringstream nodes(data);
        string val;
        getline(nodes, val, ',');
        TreeNode* root = new TreeNode(stoi(val));
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto top = q.front();
            q.pop();

            getline(nodes, val, ',');
            if (val == "#") {
                top->left = nullptr;
            } else {
                top->left = new TreeNode(stoi(val));
                q.push(top->left);
            }
            getline(nodes, val, ',');
            if (val == "#") {
                top->right = nullptr;
            } else {
                top->right = new TreeNode(stoi(val));
                q.push(top->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));