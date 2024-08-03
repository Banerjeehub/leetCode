class Solution {
public:
    int getHeight(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->left;
        }
        return height;
    }
    
    bool nodeExists(int idx, int h, TreeNode* node) {
        int left = 0, right = (1 << (h - 1)) - 1; // 2^(h-1) - 1
        for (int i = 0; i < h - 1; ++i) {
            int mid = (left + right) / 2;
            if (idx <= mid) {
                node = node->left;
                right = mid;
            } else {
                node = node->right;
                left = mid + 1;
            }
        }
        return node != nullptr;
    }
    
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int h = getHeight(root);
        if (h == 1) return 1;
        
        int left = 0, right = (1 << (h - 1)) - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nodeExists(mid, h, root)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return (1 << (h - 1)) - 1 + left;
    }
};