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
 #define st stack<TreeNode*>
 #define vin vector<int>
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vin ans;
        st s1, s2;
        s1.push(root);
        while(!s1.empty())
        {
            auto top = s1.top();
            s1.pop();
            s2.push(top);

            if(top->left) s1.push(top->left);
            if(top->right) s1.push(top->right);
        }

        while(!s2.empty())
        {
            ans.push_back(s2.top()->val);
            s2.pop();
        }

        return ans;

    }
};