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
        if(root == nullptr){
            TreeNode* newnode = new TreeNode(val);
            return newnode;
        }
       
       TreeNode* curr = nullptr ;
       TreeNode* temp = root;
        while(temp) {
             curr = temp;
            if(temp->val > val){
                temp = temp->left;
            }
            else if(temp->val < val) {
                temp= temp->right;
            }
        }

        if(curr->val < val) curr->right = new TreeNode(val);
        else curr->left = new TreeNode(val);

        return root;
    }
};