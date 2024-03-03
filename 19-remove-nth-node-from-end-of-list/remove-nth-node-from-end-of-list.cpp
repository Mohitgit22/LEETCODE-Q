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
     ListNode* removeNthFromEnd(ListNode* head, int n) {
        int c=0;
        ListNode *curr=head;
        if(head==NULL)
        return NULL;

        else if (head->next==NULL && n>=1)
        return NULL;
        else{
        while(curr!=NULL){
            c++;
            curr=curr->next;
        }
        if(c==n){
            head=head->next;
            return head;
        }
        
        int p=c-n;
        curr=head;
        int i=1;
        while(i<p){
            curr=curr->next;
            i++;
        }
        ListNode *temp=curr->next;
        curr->next=temp->next;
        delete temp;
        return head;
    }
    }
};