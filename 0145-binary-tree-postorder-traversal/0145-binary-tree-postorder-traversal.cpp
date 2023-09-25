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
class Solution {
public:
    void helper(TreeNode* root, vin &tree)
    {
        if(!root) return;
        helper(root->left, tree);
        helper(root->right, tree);
        tree.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vin tree;
        helper(root, tree);
        return tree;
    }
};