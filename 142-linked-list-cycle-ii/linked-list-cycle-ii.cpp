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

        if(head == nullptr || head->next == nullptr)
        return nullptr;

        ListNode *slow = head, *fast = head;

        while(slow!=nullptr && fast!=nullptr && fast->next!=nullptr) {
            slow = slow->next;
            fast = fast ->next->next;

            if(slow == fast) {
                slow = head;
                break;
            }
        }

        if(slow == nullptr or fast == nullptr or fast->next==nullptr)
        return nullptr;

        while(slow!=fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};