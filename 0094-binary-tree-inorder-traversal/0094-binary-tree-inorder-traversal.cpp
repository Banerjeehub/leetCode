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
 #define vin vector<int>
 #define p push_back;
class Solution {
private:
    void inorderTraversal(TreeNode* root, vin &res)
    {
        if(!root) return;
        inorderTraversal(root->left, res);
        res.push_back(root->val);
        inorderTraversal(root->right,res);

    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vin res;
        inorderTraversal(root, res);
        return res;
    }
};