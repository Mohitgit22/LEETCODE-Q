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
    vector<vector<int>> levelOrder(TreeNode* root) {
           vector<vector<int>> ans;

        if(root == nullptr)
        return ans;

        queue<TreeNode*> que;
        que.push(root);
     

        while( !que.empty() ) {
          int n = que.size();
           
          vector<int> vec;
          for(int i = 0; i < n; i++){
          TreeNode* node = que.front();
          que.pop();
          
          vec.push_back(node->val);

          if(node->left)
          que.push(node->left);
          if(node->right)
          que.push(node->right);
        }
        ans.push_back(vec);
       }
       return ans;
    }
};