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
    TreeNode* f(int inStart, int inEnd, int postStart, int postEnd, vector<int>&inorder, vector<int>&postorder, map<int, int>&mpp)
    {
        if(inStart > inEnd || postStart > postEnd) return nullptr;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mpp[root->val];
        int leftSubtreeSize = inRoot - inStart;

        root->left =  f(inStart, inRoot-1, postStart, postStart+leftSubtreeSize-1, inorder, postorder, mpp);

        root->right = f(inRoot+1, inEnd, postStart+leftSubtreeSize, postEnd-1, inorder, postorder, mpp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int>mpp;
        for(int i=0; i<inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }
        return f(0, inorder.size()-1, 0, postorder.size()-1, inorder, postorder, mpp);

        
    }
};