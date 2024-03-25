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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        return head;

        ListNode *odd= head;
        ListNode *even = head->next;
        ListNode *evenstarting = even;

        //As even node will always be ahead of odd node , 
        //all the checks will be assocaited with the even node i.e. even!=NULL and even->next!=NULL
        while(even!=NULL && even->next!=NULL) {
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = evenstarting;
        return head;
         
    }
};