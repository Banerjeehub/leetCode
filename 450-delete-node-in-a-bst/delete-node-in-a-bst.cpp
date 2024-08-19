
class Solution {
public:
    TreeNode* helper(TreeNode* root)
    {
        if(!root->right) return root->left;
        if(!root->left) return root->right;

        TreeNode* rightChild = root->right;
        TreeNode* left = rightMostNode(root->left);
        left->right = rightChild;
        return root->left;
    }
    TreeNode* rightMostNode(TreeNode* root)
    {
        if(!root->right) return root;
        return rightMostNode(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int k) {
        
        if(!root) return nullptr;

        if(root->val == k)
        {
            return helper(root);
        }
        TreeNode* curr = root;
        while(root)
        {
            if(root->val > k)
            {
                if(root->left && root->left->val == k)
                {
                    root->left = helper(root->left);
                    break;
                }
                else root = root->left;
            }
            else
            {
                if(root->right && root->right->val == k)
                {
                    root->right = helper(root->right);
                    break;

                }
                else root = root->right;
            }
        }

        return curr;

    }
};