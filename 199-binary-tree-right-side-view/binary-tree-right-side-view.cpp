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
    void dfs(TreeNode* root, vector<int>& vec, int level) {
        if(root == nullptr)
        return ;

        if(vec.size() == level) {
            vec.push_back(root->val);
        }

        dfs(root->right, vec, level+1);
        dfs(root->left, vec, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
        return {};

        if(root->left == nullptr and root->right == nullptr)
        return {root->val};

        int level = 0;
        vector<int> vec;
        dfs(root, vec, level);
        return vec;
    }
};