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
    int pairSum(ListNode* head){
         
     
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
         int maxi = INT_MIN;
         while(head) {
            int leftval = head->val;
            int rightval = prev->val;
            int sum = leftval+rightval;
            maxi = max(maxi, sum);
            head= head->next;
            prev= prev->next;
         }
         return maxi;




         //brute force -----GOOD but TLE
        //   int size = 0;
        //   ListNode *curr1 = head;
        //    ListNode *curr2 = head;
        //   while(curr1){
        //     size++;
        //     curr1 = curr1->next;
        //   }
        //   curr1=head;

        //   int p = size/2; 
        //   int i =0; 
        //   int maxi = INT_MIN;
        //   while(i<p) {
        //       int begin =i;
        //       int end = (size -1)- i;
        //       for(int j =0; j<begin; j++) {
        //         curr1= curr1->next;
        //       }
        //       int leftval = curr1->val;
        //        for(int j =0; j<end; j++) {
        //         curr2= curr2->next;
        //       }
        //       int rightval = curr2->val;
        //       int sum = leftval+rightval;
        //       maxi = max(maxi,sum);
        //       i++;
        //       curr1= head;
        //       curr2= head;
        //   }

        //  return maxi;
    }
};