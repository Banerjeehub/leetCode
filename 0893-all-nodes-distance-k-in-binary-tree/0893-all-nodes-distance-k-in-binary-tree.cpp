/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void makeMarking(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &pMarking)
    {
        queue<TreeNode* >q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i<size; i++)
            {
                auto top = q.front();
                q.pop();

                if(top->left)
                {
                    pMarking[top->left] = top;
                    q.push(top->left);
                }
                if(top->right)
                {
                    pMarking[top->right] = top;
                    q.push(top->right);
                }
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*, TreeNode*> pMarking;
        makeMarking(root, pMarking);
        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int count = 0;

        while(!q.empty())
        {
            if(count++ == k) break;
            int size = q.size();

            for(int i=0; i<size; i++)
            {
                auto temp = q.front();
                q.pop();

                if(temp->left && !visited[temp->left])
                {
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right && !visited[temp->right])
                {
                    q.push(temp->right);
                    visited[temp->right] = true;
                }

                if(pMarking[temp] && !visited[pMarking[temp]])
                {
                    q.push(pMarking[temp]);
                    visited[pMarking[temp]] = true;
                }
            }
        }

        vector<int>ans;
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            ans.push_back(top->val);
        }

        return ans;


    }
};