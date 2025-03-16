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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int , int>>> que;
        que.push({root, {0,0}});

        while(!que.empty()) {
            auto p = que.front();

            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            mp[x][y].insert(node->val);

            que.pop();
            if(node->left) que.push({node->left, {x-1, y+1}});
            if(node->right) que.push({node->right, {x+1, y+1}});
        }

        vector<vector<int>> ans;
        for(auto& [x_axis, levels] : mp) {
             vector<int>col;
           for(auto& [lvl, nodes]: levels){
              for(auto it : nodes){
                col.push_back(it);
              }
           }
           ans.push_back(col);
        }
      return ans;
    }
};