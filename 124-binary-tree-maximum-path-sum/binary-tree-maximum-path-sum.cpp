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
    int helper(TreeNode* &root, int &sum){
        if(!root) return 0;
        int ls = max(helper(root->left, sum), 0); // 2
        int rs = max(helper(root->right, sum), 0); // 3
        sum = max(sum, root->val+rs+ls);
        return root->val + max(ls, rs);
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        helper(root, sum);
        return sum;
    }
};