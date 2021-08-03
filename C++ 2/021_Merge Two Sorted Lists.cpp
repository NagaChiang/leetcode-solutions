class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        }
        
        if (l2 == nullptr) {
            return l1;
        }
        
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        ListNode newPreRoot;
        ListNode* tail = &newPreRoot;
        while (node1 != nullptr && node2 != nullptr) {
            if (node1->val < node2->val) {
                tail->next = node1;
                node1 = node1->next;
            } else {
                tail->next = node2;
                node2 = node2->next;
            }
            
            tail = tail->next;
        }
        
        tail->next = node1 != nullptr ? node1 : node2;
        
        return newPreRoot.next;
    }
};