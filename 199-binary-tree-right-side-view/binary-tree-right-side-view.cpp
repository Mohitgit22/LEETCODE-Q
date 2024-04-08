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
    void rightview(TreeNode *node, vector<int>& ans, int level) {
            if(node == nullptr)
              return;

            if(ans.size() == level)
               ans.push_back(node->val);
             rightview(node->right,ans, level+1);
             rightview(node->left,ans, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr)
          return ans;
        
        rightview(root, ans, 0);
        return ans;
    }
};