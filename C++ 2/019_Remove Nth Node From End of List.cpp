class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHead = new ListNode(0, head);
        ListNode* slow = newHead;
        ListNode* fast = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* removeNode = slow->next;
        slow->next = slow->next->next;
        delete removeNode;
        
        head = newHead->next;
        delete newHead;
        
        return head;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode** slowPtr = &head;
        ListNode* fast = head;
        for (int i = 0; i < n - 1; i++) {
            fast = fast->next;
        }
        
        while (fast->next != nullptr) {
            slowPtr = &((*slowPtr)->next);
            fast = fast->next;
        }
        
        ListNode* removeNode = *slowPtr;
        *slowPtr = (*slowPtr)->next;
        delete removeNode;
        
        return head;
    }
};