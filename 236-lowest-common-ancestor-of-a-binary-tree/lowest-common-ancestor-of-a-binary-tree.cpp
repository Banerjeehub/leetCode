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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*>parent;
        queue<TreeNode*>qu;
        qu.push(root);
        parent[root] = nullptr;

        while(parent.find(p) == parent.end() || parent.find(q) == parent.end())
        {
            auto top = qu.front();
            qu.pop();

            if(top->left)
            {
                parent[top->left] = top;
                qu.push(top->left);
            }
            if(top->right)
            {
                parent[top->right] = top;
                qu.push(top->right);
            }

        }

        set<TreeNode*>st;
        while(p)
        {
            st.insert(p);
            p = parent[p];
        }

        while(st.find(q) == st.end())
        {
            q = parent[q];
        }

        return q;
    }
};