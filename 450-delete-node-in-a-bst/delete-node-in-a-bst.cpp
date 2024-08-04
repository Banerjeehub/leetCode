/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode* root) {
        if (!root->left)
            return root->right;
        if (!root->right)
            return root->left;

        TreeNode* rightChild = root->right;
        TreeNode* lastNode = rightMostNode(root->left);
        lastNode->right = rightChild;
        return root->left;
    }
    TreeNode* rightMostNode(TreeNode* root) {
        if (!root->right)
            return root;
        return rightMostNode(root->right);
    }
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (!root)
            return NULL;

        if (root->val == key) {
            return helper(root);
        }
        TreeNode* temp = root;
        while (root) {
            if (root->val > key) {
                if (root->left && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                } else {
                    root = root->left;
                }
            } else {
                if (root->right && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                } else {
                    root = root->right;
                }
            }
        }

        return temp;
    }
};