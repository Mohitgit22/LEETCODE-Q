/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int height(TreeNode* root)  {
        if(root == nullptr)
        return 0;

        return 1 + max(height(root->left), height(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
        return 0;

       
       int lh = height(root->left);
       int rh = height(root->right);

        ans = max(ans, lh + rh);

       diameterOfBinaryTree(root->left);
       diameterOfBinaryTree(root->right);

       return ans;
    }
};