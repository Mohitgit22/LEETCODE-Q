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
      ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        ListNode* front = head->next;
        while(temp){
            front = temp->next;
            temp->next = prev;
            prev= temp;
            temp = front;
        }
        return prev;
      }

    ListNode* doubleIt(ListNode* head) {
        ListNode *temp = reverse(head);
        ListNode *ans = nullptr;
        ListNode *tail = nullptr;

        int rem = 0;
        while(temp){
             int digit = 2 * temp->val + rem;
             rem = digit / 10;
             int actualdigit = digit % 10;
             ListNode* ansdigit = new ListNode(actualdigit);

             if(ans==nullptr){
                ans = ansdigit;
                tail = ans;
             }else{
                tail->next = ansdigit;
                tail=tail->next;
             }
            temp =temp->next;
        }
        if(rem>0)
           tail->next = new ListNode(rem);
        
        return reverse(ans);
    }
};