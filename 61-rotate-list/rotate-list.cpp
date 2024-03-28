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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || k==0)
        return head;

         int cnt = 0;
         ListNode *curr = head;
         ListNode *newhead = curr;
         while(curr){
            cnt++;
            curr= curr->next;
         }
         int s = k%cnt;
         if(s == 0)
         return head;

         curr = head;
         int p =cnt-s-1;
         while(p>0){
            curr =curr->next;
            p--;
         }

         ListNode *temp = curr->next;
         newhead = temp;
          //make the end 
        curr->next = NULL;  
        while(temp->next!=NULL)
            temp=temp->next;
         
        temp->next = head;
        return newhead;
    }
};