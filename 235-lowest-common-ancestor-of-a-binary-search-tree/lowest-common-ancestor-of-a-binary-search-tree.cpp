/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *ans = root;
        while(root) {

            if((root->val <= p->val && root->val >= q->val) || (root->val >= p->val && root->val <= q->val)) 
                return ans;
            
            else if(root->val > p->val && root->val > q->val){
                root = root->left;
                   ans = root;
            }else if(root->val < p->val && root->val < q->val){
                root = root -> right;
                ans = root;
            }
        }
        return ans;
    }
};