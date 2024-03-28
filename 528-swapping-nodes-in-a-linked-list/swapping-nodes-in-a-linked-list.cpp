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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head == NULL || head ->next ==NULL)
        return head;

          int size = 0;
          ListNode *curr = head;
          while(curr){
            size++;
            curr = curr->next;
          }

          int s = size-k;
          curr=head;
          for(int i =0; i<k-1; i++)
            curr=curr->next;
          ListNode *begin = curr;

          curr=head;
          
          for(int i =0; i<s; i++)
            curr=curr->next;
          ListNode *end = curr;
      
          int startdata = begin->val;
          begin->val = end->val;
          end->val = startdata;
    return head;
    }
};