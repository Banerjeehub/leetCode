class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
           
            vector<int>temp;
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                auto top = q.front();
                q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                temp.push_back(top->val);
            }

            res.push_back(temp);
        }


        return res;

    }
};