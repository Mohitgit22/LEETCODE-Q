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
   int ans(TreeNode *root, int& cnt, int k) {
        if (!root)
            return 0;

        int left = ans(root->left, cnt, k);
        if (left)
            return left;
        
        cnt++;
        if (cnt == k)
            return root->val;

        return ans(root->right, cnt, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return ans(root, cnt, k);
    }
};
    