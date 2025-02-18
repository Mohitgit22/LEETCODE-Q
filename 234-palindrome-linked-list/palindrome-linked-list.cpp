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
    ListNode* reverse(ListNode* head){
        if(head == nullptr or head->next == nullptr)
        return head;

        ListNode *curr = head, *prev = nullptr, *front = nullptr;

        while(curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head->next == nullptr) 
        return true;

        // finding the middle of the linked list
        ListNode *slow = head, *fast = head;
        while(fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newHead = reverse(slow);
        ListNode* curr = newHead, *temp = head;
        
        while(curr){
            if(head->val != curr->val) 
            return false;

            head = head->next;
            curr = curr->next;
        }
        return true;
    }
};