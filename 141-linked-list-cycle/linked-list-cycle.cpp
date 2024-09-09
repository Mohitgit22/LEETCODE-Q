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
    bool hasCycle(ListNode *head) {
        //floyyd Cycle method or fast slow method
        // ListNode *slow  = head, *fast = head;
        // while(slow!=NULL && fast!=NULL && fast->next){
        //     slow = slow->next;
        //     fast = fast->next->next;
        //     if(slow == fast)
        //     return true;
        // }
        // return false;



        ListNode *slow = head, *fast = head;
        while(slow!=nullptr && fast!=nullptr && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
            return true;
        } 
        return false;
    }
};