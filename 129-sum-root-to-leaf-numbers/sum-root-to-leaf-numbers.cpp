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
    int dfs(TreeNode *node, int ans) {
        if(node == nullptr)
            return 0;

         ans = ans * 10 + node->val;
         if(!node->left && !node->right) 
               return ans;
    
          return dfs(node->left, ans) + dfs(node->right, ans);
        }

    int sumNumbers(TreeNode* root) {
          int ans = 0;
          return  dfs(root, ans);
    }
};