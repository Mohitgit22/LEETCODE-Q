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
        queue<TreeNode*> que;
         vector<vector<int>> ans;
        vector<int> vec;

        if(root == nullptr)
        return ans;

        que.push(root);
        while(!que.empty()) {
        int size = que.size();
        for(int i = 0; i< size; i++) {
            TreeNode* curr = que.front();
            vec.push_back(curr->val);
            que.pop();
            if(curr->left) que.push(curr->left);
            if(curr->right) que.push(curr->right);
             }
          ans.push_back(vec);
          vec.clear();
        }
        return ans;
    }
};