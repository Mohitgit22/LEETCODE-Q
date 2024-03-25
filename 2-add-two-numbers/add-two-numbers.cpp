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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *t1 =l1;
        ListNode *t2 =l2;
        int carry=0;
        ListNode *dummynode = new ListNode(-1);
        ListNode *curr = dummynode;
        while(t1 || t2) {
             int sum = carry;
            if(t1) 
            sum = sum + t1->val;
            if(t2)
            sum = sum + t2->val;
    
            //creating a new node for the sum obtained
            ListNode *digit = new ListNode(sum%10);
            //updating the carry;
            carry = sum/10;
            //moving to the latest postion in new building linkedlist or answer LL
            curr->next = digit;
            curr=curr->next;
     
            //moving to next digits or next nodes of both LL
            if(t1)
            t1 = t1->next;
            if(t2)
            t2 = t2->next;
        }
        if(carry){
            ListNode *newnode = new ListNode(carry);
            curr->next = newnode;
        }
        return dummynode ->next;
    }
};