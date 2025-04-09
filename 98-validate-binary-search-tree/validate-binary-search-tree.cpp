// class Solution {
// public:
//     long prev = LONG_MIN;

//     bool inorder(TreeNode* root) {
//         if (!root) return true;

//         if (!inorder(root->left)) return false;

//         if (root->val <= prev) return false;
//         prev = root->val;

//         return inorder(root->right);
//     }

//     bool isValidBST(TreeNode* root) {
//         return inorder(root);
//     }
// };


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        long prev = LONG_MIN;

        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top(); st.pop();
            if (curr->val <= prev) return false;
            prev = curr->val;

            curr = curr->right;
        }

        return true;
    }
};