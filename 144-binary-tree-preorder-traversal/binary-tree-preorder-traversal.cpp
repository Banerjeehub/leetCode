class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        
        while (curr) {
            if (!curr->left) {
                // Process the current node (preorder visit)
                ans.push_back(curr->val);
                // Move to the right subtree
                curr = curr->right;
            } else {
                TreeNode* prev = curr->left;

                // Find the rightmost node in the left subtree or the thread
                while (prev->right && prev->right != curr) {
                    prev = prev->right;
                }

                // If the right pointer is null, make the current node the right child
                if (!prev->right) {
                    prev->right = curr;
                    // Process the current node (preorder visit)
                    ans.push_back(curr->val);
                    // Move to the left subtree
                    curr = curr->left;
                } else {
                    // Restore the tree structure
                    prev->right = NULL;
                    // Move to the right subtree
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};