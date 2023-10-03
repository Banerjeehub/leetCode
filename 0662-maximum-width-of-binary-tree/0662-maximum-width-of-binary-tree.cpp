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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        int ans = 0;
        while(!q.empty())
        {
            int size = q.size();
            long long int min = q.front().second;
           
            int first,last;
            for(int i=0; i<size; i++)
            {
                auto node = q.front().first;
                int64_t curr_idx = q.front().second - min;
                q.pop();
                if(i == 0) first = curr_idx;
                if(i == size-1) last = curr_idx;

                if(node->left)
                {
                    q.push({node->left, 2*curr_idx + 1});
                }
                if(node->right)
                {
                    q.push({node->right, 2*curr_idx + 2});
                }
            }
            ans = max(ans, last-first+1);
        }

        return ans;
    }
};