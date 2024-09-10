/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       map<ListNode*, int> mpp;
       ListNode *curr = head;

       while(curr!= nullptr) {
        if(mpp[curr])
        return curr;

        mpp[curr] = 1;
        curr = curr->next;
       }
       return nullptr;

    }
};