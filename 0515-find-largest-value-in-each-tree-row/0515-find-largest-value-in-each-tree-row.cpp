class Solution{
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        vector<int>res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int maxi = INT_MIN;
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                auto it = q.front();
                q.pop();
                maxi = max(maxi, it->val);

                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            res.push_back(maxi);
        }
        return res;
    }
};