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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next ==NULL)
        return;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *beforemid = NULL;
        while(fast!=NULL && fast->next!=NULL){
            beforemid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // ListNode *mid = slow;
          beforemid->next = NULL;
          ListNode *mid = slow;


          //reversal of 2nd part
          ListNode *temp = mid;
          ListNode *prev = NULL,*front = NULL;
         while(temp){
              front = temp->next;
              temp->next = prev;
              prev = temp;
              temp = front;
         };
            
        
         while(head && prev) {
            temp = head->next;
            front = prev ->next;
            head->next = prev;
            if(temp==NULL){
                prev->next=front;
                if(front!=NULL)
                front->next=NULL;
                break;
            }
            prev->next = temp;
            head = temp;
            prev = front;
         }
        //  if(prev!=NULL)
        //    prev->next =slow;
    }
};