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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr)
         {
            TreeNode *root = new TreeNode(val);
            return root;
         }
         TreeNode *curr = root;
         while(curr) {
            if(curr -> val < val){
             if(curr->right == nullptr){
                curr->right = new TreeNode(val);
                 return root;
             }
             else 
               curr = curr->right;
            }else if(curr -> val > val) {
                if(curr->left == nullptr){
                    curr->left =new TreeNode(val);
                    return root; 
                    }
                    else 
                    curr = curr->left;
            }
         }
         return root;
    }
};