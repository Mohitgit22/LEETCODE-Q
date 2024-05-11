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
    vector<int> traverse;
    void inorder(TreeNode *root) {
    if(root == nullptr)
      return ;

    inorder(root->left);
    traverse.push_back(root->val);
    inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);

       int left = 0, right = traverse.size()-1;
       while(left < right) {
        int sum = traverse[left] + traverse[right];
        if(sum == k)
           return true;
        else if(sum > k)
           right--;
        else 
          left++;
       }
       return false;
    }
};