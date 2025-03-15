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

    int height(TreeNode* root) {
        if(root == nullptr)
        return 0;

        return 1+max(height(root->left), height(root->right));
    }

    void inorder(TreeNode* root, vector<TreeNode*> &vec) {
       if(root == nullptr)
       return ;

       inorder(root->left, vec);
       vec.push_back(root);
       inorder(root->right, vec);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
        return true;

        vector<TreeNode*> vec;

        inorder(root, vec);
        int  height_left_subtree;
        int  height_right_subtree;
        for(int i = 0; i < vec.size(); i++) {
            TreeNode* curr = vec[i];
            if(curr->left)
            height_left_subtree = height(curr->left);
            if(curr->right)
            height_right_subtree = height(curr->right);
            if(abs(height_left_subtree - height_right_subtree)> 1)
            return false;
     
           height_left_subtree = 0;
           height_right_subtree = 0;

        }

        return true;
    }
};