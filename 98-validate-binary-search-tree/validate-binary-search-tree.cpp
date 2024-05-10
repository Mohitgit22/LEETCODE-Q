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

     bool isValidbyRange(TreeNode* root, long long int mini, long long int maxi) {
        if(root == nullptr)
         return true;

        if(root ->val >= maxi || root->val <= mini)
          return false;

        return isValidbyRange(root->left,mini, root->val) and isValidbyRange(root->right,root->val, maxi);
     }
    bool isValidBST(TreeNode* root) {
        long long int mini = (long long)INT_MIN-1, maxi = (long long)INT_MAX+1;
        return isValidbyRange(root, mini,maxi);
    }
};