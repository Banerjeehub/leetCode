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
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, nullptr, nullptr);
    }
    
private:
    bool isValidBSTHelper(TreeNode* node, TreeNode* minNode, TreeNode* maxNode) {
        if (!node) return true;
        
        // If the current node's value is not within the valid range, return false
        if ((minNode && node->val <= minNode->val) || (maxNode && node->val >= maxNode->val)) {
            return false;
        }
        
        // Check recursively for the left and right subtrees
        return isValidBSTHelper(node->left, minNode, node) &&
               isValidBSTHelper(node->right, node, maxNode);
    }
};