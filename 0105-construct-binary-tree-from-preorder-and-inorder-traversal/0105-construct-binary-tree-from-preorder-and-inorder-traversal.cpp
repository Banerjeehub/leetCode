class Solution {
public:

    TreeNode* helper(vector<int>&inorder, int is, int ie, vector<int>&preorder, int ps, 
        int pe, map<int, int>&mpp)
    {
        if(is > ie || ps > pe) return NULL;

        TreeNode* root = new TreeNode(preorder[ps]);

        int idxRoot = mpp[preorder[ps]];

        int numsLeft = idxRoot - is;

        root->left = helper(inorder, is, idxRoot-1, preorder, ps+1, ps+numsLeft, mpp);

        root->right = helper(inorder, idxRoot+1, ie, preorder, ps+numsLeft+1,pe, mpp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size()) return NULL;

        map<int, int>mpp;

        for(int i=0; i<inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }
        return helper(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1, mpp);
    }
};