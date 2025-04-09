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
        unordered_set<TreeNode*>ancestors;
        queue<TreeNode*>qu;
        qu.push(root);
        parent[root] = nullptr;

        while(!parent.count(p) || !parent.count(q))
        {
            auto curr_node = qu.front();
            qu.pop();

            if(curr_node->left)
            {
                parent[curr_node->left] = curr_node;
                qu.push(curr_node->left);
            }
            if(curr_node->right)
            {
                parent[curr_node->right] = curr_node;
                qu.push(curr_node->right);
            }

        }

        // saving the ancestors of p
        while(p)
        {
            ancestors.insert(p);
            p = parent[p];
        }

        while(ancestors.find(q) == ancestors.end())
        {
            q = parent[q];
        }
        return q;
    }
};