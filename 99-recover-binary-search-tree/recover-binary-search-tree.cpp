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
    void inorder(TreeNode* root,TreeNode* &prev, TreeNode* &first,TreeNode* &middle,TreeNode* &last) {
         if(root == nullptr)
           return ;

        inorder(root->left, prev, first, middle, last);

        if(prev!=nullptr and root->val < prev->val) {

            if(first == nullptr){
                first = prev;
                middle = root;
            }
            else
              last = root;
        }
       
       prev = root;
       inorder(root->right, prev, first, middle, last);
    }

    void recoverTree(TreeNode* root) {
        TreeNode* prev = new TreeNode(INT_MIN);
        TreeNode* first = nullptr;
        TreeNode* middle = nullptr;
        TreeNode* last = nullptr;
        inorder(root, prev, first, middle, last);

        if(first && last) 
         swap(first->val , last->val);
        else if(first && middle) 
         swap(first->val , middle->val);
         
    }
};