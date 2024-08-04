class Solution {
public:
    // Helper function to validate BST with min and max constraints
    bool validate(TreeNode* root, long long min, long long max) {
        if (!root) return true;
        if (root->val >= max || root->val <= min) return false;

        // Check the left and right subtrees with updated constraints
        return validate(root->left, min, root->val) && validate(root->right, root->val, max);
    }

    // Main function to check if the tree is a valid BST
    bool isValidBST(TreeNode* root) {
        return validate(root, std::numeric_limits<long long>::min(), std::numeric_limits<long long>::max());
    }
};