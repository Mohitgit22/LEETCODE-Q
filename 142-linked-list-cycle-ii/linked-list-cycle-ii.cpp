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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr or head->next == nullptr or head->next->next == nullptr) 
        return nullptr;

        ListNode *slow = head, *fast = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                slow = head;
                break;
            }
        }

        if(fast == nullptr or fast->next == nullptr )
        return nullptr;

        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};