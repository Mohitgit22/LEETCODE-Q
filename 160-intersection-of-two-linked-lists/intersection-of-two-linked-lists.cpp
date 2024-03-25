/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
     int len(ListNode *head) {
        int length = 0;
          while(head) {
            length++;
            head = head->next;
          }
          return length;
     }

     ListNode *collide(ListNode *small, ListNode *larger, int diff) {
              while(diff) {
                larger = larger->next;
                diff --;
              }
              
              while(small!=larger) {
                small = small->next;
                larger = larger->next;
              }
              return small;
     }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
        return NULL;

        ListNode *temp1 = headA;
        ListNode *temp2 = headB;
        int len1 = len(headA), len2 = len(headB);

        if(len1> len2){
            return collide(headB, headA, len1-len2);
        }else{
            return collide(headA, headB, len2-len1);
        }
        return NULL;
    }
};