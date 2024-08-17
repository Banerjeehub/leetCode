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
        TreeNode* current = root;
        
        while (current) {
            if (p->val < current->val && q->val < current->val) {
                // Both nodes are in the left subtree
                current = current->left;
            } 
            else if (p->val > current->val && q->val > current->val) {
                // Both nodes are in the right subtree
                current = current->right;
            } 
            else {
                // We have found the split point, i.e., the LCA node
                return current;
            }
        }
        
        return nullptr; // This line should not be reached if p and q are guaranteed to be in the tree
    }
};