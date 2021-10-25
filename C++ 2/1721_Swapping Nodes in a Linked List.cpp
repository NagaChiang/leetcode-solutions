class Solution {
public:
  ListNode* swapNodes(ListNode* head, int k) {
    ListNode preHead = ListNode(0, head);
    ListNode* slow = &preHead;
    ListNode* fast = &preHead;
    for (int i = 0; i < k; i++) {
      fast = fast->next;
    }

    ListNode* n1 = fast;

    while (fast != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }

    ListNode* n2 = slow;
    swap(n1->val, n2->val);

    return head;
  }
};