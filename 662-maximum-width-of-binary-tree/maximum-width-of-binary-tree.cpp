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
        
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        int maxWidth = 0;

        while(!q.empty())
        {
            int min =  q.front().second;
            int size = q.size();
            int first, last;
            for(int i=0; i<size; i++)
            {
                auto top = q.front();
                TreeNode* node = top.first;
                int idx = top.second;
                q.pop();
                int64_t  curr_idx = idx - min;
                if(i == 0) first = curr_idx;
                if(i == size-1)last = curr_idx;
                if(node->left)
                {
                    q.push({node->left, 2*curr_idx+1});
                }
                if(node->right)
                {
                    q.push({node->right, 2*curr_idx+2});
                }
            }
            maxWidth = max(maxWidth, last-first+1);

        }

        return maxWidth;
    }
};