class Solution {
public:
    TreeNode* ans = nullptr;
    
    bool helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return false;
        
        bool mid = (root == p || root == q);
        bool left = helper(root->left, p, q);
        bool right = helper(root->right, p, q);
        
        // Check if current node is LCA
        if ((mid && left) || (mid && right) || (left && right)) {
            ans = root;
        }
        
        return mid || left || right;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root, p, q);
        return ans;
    }
};
