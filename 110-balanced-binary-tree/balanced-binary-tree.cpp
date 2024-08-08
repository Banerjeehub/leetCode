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
    int f(TreeNode* root, bool &ans)
    {
        if(!root) return 0;

        int lh = f(root->left, ans);
        int rh = f(root->right, ans);

        if(abs(lh - rh) > 1) ans = false;

        return 1 + max(lh, rh);

    }
    bool isBalanced(TreeNode* root) {
        bool ans = true;

        f(root, ans);
        return ans;


    }
};