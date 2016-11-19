#include <string.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{

public:

	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		if(!head)
			return head;

		// Move node to n nodes ahead
		ListNode* preHead = new ListNode(0);
		preHead->next = head;
		ListNode* nodeBeforeTarget = preHead;
		ListNode* node = head;
		for(int i = 0; i < n; i++)
			node = node->next;

		// Move both pointers until the end
		while(node)
		{
			nodeBeforeTarget = nodeBeforeTarget->next;
			node = node->next;
		}

		// Remove node
		nodeBeforeTarget->next = nodeBeforeTarget->next->next;

		return preHead->next;
	}
};