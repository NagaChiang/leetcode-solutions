class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* last = nullptr;
        ListNode* current = head;
        while (current) {
            ListNode* next = current->next;
            current->next = last;

            last = current;
            current = next;
        }
        
        return last;
    }
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        
        return newHead;
    }
};