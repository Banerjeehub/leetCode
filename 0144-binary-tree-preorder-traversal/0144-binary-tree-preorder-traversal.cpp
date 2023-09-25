#define vin vector<int>
class Solution {
public:
    void helper(TreeNode* root, vin &res)
    {
        if(!root) return;

        res.push_back(root->val);
        helper(root->left, res);
        helper(root->right, res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vin res;
        helper(root, res);
        return res;
    }
};