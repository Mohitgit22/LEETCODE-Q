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
    int findDia(TreeNode* node, int& maxi){
        if(node == nullptr)
        return 0;

        int left = findDia(node->left, maxi);
        int right = findDia(node->right, maxi);

        maxi = max(maxi, left+right);
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
        return 0;

        int maxi = 0;
        findDia(root, maxi);
        return maxi;
    }
};