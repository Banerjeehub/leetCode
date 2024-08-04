class Solution {
public:

    TreeNode* f(int inStart, int inEnd, int preStart, int preEnd, map<int, int>&mpp, vector<int>& inorder, vector<int>& preorder)
    {
        if(preStart > preEnd || inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int leftEle = mpp[root->val] - inStart;
        int inRoot = mpp[root->val];

        root->left = f(inStart, inRoot-1, preStart+1, preStart+leftEle, mpp, inorder, preorder);
        root->right = f(inRoot+1, inEnd, preStart+leftEle+1, preEnd, mpp, inorder, preorder);

        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int>mpp;

        for(int i=0; i<inorder.size(); i++)
        {
            mpp[inorder[i]] = i;
        }

        TreeNode* root = f(0, inorder.size()-1, 0, preorder.size()-1, mpp, inorder, preorder);
        return root;
    }
};