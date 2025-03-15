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
    bool equal(TreeNode* node1, TreeNode* node2) {
        if (node1 == nullptr && node2 == nullptr) return true;

        if((node1 == nullptr and node2!= nullptr) || (node1 != nullptr and node2 == nullptr))
         return false;

         return (node1->val == node2->val);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr and q == nullptr)
        return true;

        bool curr_noderesult = equal(p, q);
        if(curr_noderesult == false)
        return false;

       return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};