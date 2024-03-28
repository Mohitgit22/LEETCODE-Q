/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *curr = head;
        vector<int> ans;
        while(curr){
            ListNode * temp = curr->next;
            bool flag = true;
            while(temp){
                if(temp->val > curr->val){
                    ans.push_back(temp->val);
                    flag= false;
                    break;
                }
                temp= temp->next;
            }
            if(flag == true)
            ans.push_back(0);
            curr=curr->next;
        }
     return ans;
    }
};