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
    ListNode* partition(ListNode* head, int x) {
           if(head == nullptr || head -> next == nullptr)
           return head;
           
           ListNode *smallerHead = new ListNode();//dummy head for smaller values
           ListNode *smallerTail = smallerHead;
           ListNode *largerHead = new ListNode();//dummy head for larger values
           ListNode *largerTail = largerHead;

           ListNode *curr = head;
           while(curr) {
            if(curr->val < x) {
                smallerTail -> next = curr;
                smallerTail = smallerTail->next;
            }else{
                largerTail -> next = curr;
                largerTail = largerTail->next;
            }
            curr = curr->next;
           }
           
           //connect the 2 LL
           smallerTail->next = largerHead->next;
           largerTail->next = NULL;
       
           //Update Head
           head = smallerHead->next;

           //Free the dummy Heads
           delete smallerHead;
           delete largerHead;

            return head;
             }
};