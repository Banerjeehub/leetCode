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
    void markParents(TreeNode* root, map<TreeNode*, TreeNode*>& mpp) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
             TreeNode* top = q.front();
            q.pop();

            if (top->left) {
                mpp[top->left] = top;
                q.push(top->left);
            }
            if (top->right) {
                mpp[top->right] = top;
                q.push(top->right);
            }
        }
    }
    vector<int> nodesInKDistance(TreeNode* root, TreeNode* target, int k,
                                 map<TreeNode*, TreeNode*>& mpp) {
        map<TreeNode*, bool> visited;
        visited[target] = true;
        queue<TreeNode*> q;
        q.push(target);
        int count = 0;
        while (!q.empty()) {
            if (count++ == k)
                break;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                auto top = q.front();
                q.pop();

                if (top->left && !visited[top->left]) {
                    q.push(top->left);
                    visited[top->left] = true;
                }
                if (top->right && !visited[top->right]) {
                    q.push(top->right);
                    visited[top->right] = true;
                }
                if (mpp[top] && !visited[mpp[top]]) {
                    q.push(mpp[top]);
                    visited[mpp[top]] = true;
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        map<TreeNode*, TreeNode*> parents;
        markParents(root, parents);
        return nodesInKDistance(root, target, k, parents);
    }
};