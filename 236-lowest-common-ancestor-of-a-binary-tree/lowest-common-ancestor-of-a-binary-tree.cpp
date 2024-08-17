class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Stack for tree traversal
        stack<TreeNode*> nodeStack;
        // Map to keep track of parent pointers for each node
        unordered_map<TreeNode*, TreeNode*> parent;
        // Initialize the parent of the root as NULL
        parent[root] = nullptr;
        nodeStack.push(root);

        // Iterate until both nodes are found
        while (parent.find(p) == parent.end() || parent.find(q) == parent.end()) {
            TreeNode* node = nodeStack.top();
            nodeStack.pop();

            // If the current node has a left child, process it
            if (node->left) {
                parent[node->left] = node;
                nodeStack.push(node->left);
            }
            // If the current node has a right child, process it
            if (node->right) {
                parent[node->right] = node;
                nodeStack.push(node->right);
            }
        }

        // Set to store the ancestors of p
        unordered_set<TreeNode*> ancestors;

        // Process all ancestors for node p using parent pointers
        while (p) {
            ancestors.insert(p);
            p = parent[p];
        }

        // The first ancestor of q which appears in p's ancestor set is the LCA
        while (ancestors.find(q) == ancestors.end()) {
            q = parent[q];
        }

        return q;
    }
};