class Solution {
public:
    TreeNode* getNode(TreeNode* root, int start, map<TreeNode*, TreeNode*>&mpp)
    {
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* target = nullptr;
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            if(top->val == start) target = top;

            if(top->left)
            {
                mpp[top->left] = top;
                q.push(top->left);
            }
            if(top->right)
            {
                mpp[top->right] = top;
                q.push(top->right);
            }
        }
        return target;
    }
    int ans(TreeNode* root, map<TreeNode*, TreeNode*>&mpp, TreeNode* target)
    {
        queue<TreeNode*>q;
        q.push(target);
        map<TreeNode*, bool>visited;
        visited[target] = true;
        int ans = 0;
        while(!q.empty())
        {
            bool flag = 0;
            int size = q.size();

            for(int i=0; i<size; i++)
            {
                auto top = q.front();
                q.pop();

                if(top->left && !visited[top->left])
                {
                    flag = 1;
                    q.push(top->left);
                    visited[top->left] = true;
                }
                if(top->right && !visited[top->right])
                {
                    flag = 1;
                    q.push(top->right);
                    visited[top->right] = true;
                }
                if(mpp[top] && !visited[mpp[top]])
                {
                    flag = 1;
                    q.push(mpp[top]);
                    visited[mpp[top]] = true;
                }
            }
            if(flag) ans++;
        }

        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        
        map<TreeNode*, TreeNode*>mpp;
        TreeNode* target = getNode(root, start, mpp);
        return ans(root, mpp, target);
    }
};