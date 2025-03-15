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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> ans;

        if(root == nullptr)
        return ans;

        queue<TreeNode*> que;
        que.push(root);

        vector<int> vec;
        bool left_to_right = true;
        while(!que.empty()){
            int size = que.size();
            // cout<<size<<endl;
            for(int i = 0; i < size; i++) {
                TreeNode* curr = que.front();
                que.pop();
                vec.push_back(curr->val);
               
               if(curr->left) que.push(curr->left);
               if(curr->right) que.push(curr->right);
            }

            if(left_to_right == false) 
            reverse(vec.begin(),vec.end());

            ans.push_back(vec);
            vec.clear();

            left_to_right = !left_to_right;
        }
        return ans;
    }
};