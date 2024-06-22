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
    ListNode* sortList(ListNode* head) {
        vector<int> nodes;

        ListNode* curr = head;
        while(curr!=NULL) {
            int x = curr->val;
            nodes.push_back(x);
            curr = curr->next;
        }

        if(nodes.size() == 0 || nodes.size() == 1)
        return head;

        sort(nodes.begin(), nodes.end());

        ListNode* dummy = new ListNode(0);
        curr = dummy;
        for(int it : nodes) {
            curr->next = new ListNode(it);
            curr = curr->next;  
        }
        ListNode *newhead = dummy->next;
        delete dummy;
        return newhead;
    }
};