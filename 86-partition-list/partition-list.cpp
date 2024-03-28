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
         if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* smallerHead = new ListNode(); // Dummy head for smaller values
        ListNode* smallerTail = smallerHead;
        ListNode* largerHead = new ListNode(); // Dummy head for larger values
        ListNode* largerTail = largerHead;

        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val < x) {
                smallerTail->next = curr;
                smallerTail = smallerTail->next;
            } else {
                largerTail->next = curr;
                largerTail = largerTail->next;
            }
            curr = curr->next;
        }

        // Connect the two partitions
        smallerTail->next = largerHead->next;
        largerTail->next = nullptr;

        // Update head
        head = smallerHead->next;

        // Free the dummy heads
        delete smallerHead;
        delete largerHead;

        return head;
    }
    //     if(head == NULL || head->next==NULL)
    //     return head;
    
    //    ListNode* curr = head;
    //    ListNode *smallerhead = NULL;
    //    ListNode *largerhead = NULL;
    //    ListNode *head1 = NULL, *head2 =NULL;
    //    while(curr){
    //     if(curr->val < x){
    //             if(smallerhead==NULL){
    //               smallerhead = curr;
    //                head1 = smallerhead;
    //             }
    //             else{
    //                 smallerhead->next = curr;
    //                 smallerhead = smallerhead->next;
    //                 curr=curr->next;
    //             } 
    //     }else{
    //          if(largerhead==NULL){
    //               largerhead = curr;
    //                head2 = largerhead;
    //          }
    //             else{
    //                 largerhead->next = curr;
    //                 largerhead = largerhead->next;
    //                 curr=curr->next;
    //             } 
    //     }
    //    }
    //    //connect both the Linked Lists
    //    smallerhead->next = head2;
    //    largerhead->next=NULL;
    //    delete smallerhead;
    //    delete largerhead;
    //    delete head2;
    //    return head1;
    // }
};