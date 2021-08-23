class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        
        ListNode* mid = getMiddleNode(head);
        ListNode* tail = reverseList(mid->next);
        mid->next = nullptr;
        
        ListNode* node1 = head;
        ListNode* node2 = tail;
        while (node1 != nullptr && node2 != nullptr) {
            if (node1->val != node2->val) {
                return false;
            }
            
            node1 = node1->next;
            node2 = node2->next;
        }
        
        return true;
    }
    
    ListNode* getMiddleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
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