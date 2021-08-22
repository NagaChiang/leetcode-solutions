class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }

        ListNode* mid = middleNode(head);
        ListNode* head2 = reverseList(mid->next);
        mid->next = nullptr;
        
        ListNode* node1 = head;
        ListNode* node2 = head2;
        while (node1 != nullptr && node2 != nullptr) {
            ListNode* next1 = node1->next;
            ListNode* next2 = node2->next;
            
            node1->next = node2;
            node2->next = next1;
            node1 = next1;
            node2 = next2;
        }
    }
    
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* last = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            current->next = last;

            last = current;
            current = next;
        }
        
        return last;
    }
};