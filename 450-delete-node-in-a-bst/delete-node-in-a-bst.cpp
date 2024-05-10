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
   TreeNode* findlastright(TreeNode *temp) {
        while(temp->right){
         temp=temp->right;
        }
        return temp;
   }
  TreeNode*  helper(TreeNode* curr, int key) {
           if(curr->left == nullptr)
             return curr->right;
            if(curr->right == nullptr)
              return curr->left;
            
            TreeNode *rightSide = curr->right;
            TreeNode *lastRight  = findlastright(curr->left);
            lastRight->right = rightSide;
            return curr->left;

    }
    TreeNode* deleteNode(TreeNode* root, int key) {
         if(root == nullptr)
           return nullptr;

        if(root->val == key)
         return helper(root, key);

        TreeNode *curr = root;
        while(curr) {
            if(curr->val > key) {
            if(curr -> left != nullptr and curr->left->val == key){
                curr->left = helper (curr->left, key);
                break;
            }else 
            curr= curr->left;
            }else {
                if(curr->right != nullptr and curr->right->val == key) {
                    curr->right =  helper(curr->right, key);
                    break;
                }else 
                 curr = curr->right;
            }
        }
        return root; 
    }
};