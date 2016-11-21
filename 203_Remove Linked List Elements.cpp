#include <stdlib.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{

public:

	ListNode* removeElements(ListNode* head, int val)
	{
		ListNode* prehead = new ListNode(0);
		prehead->next = head;
		ListNode* node = prehead;
		while(node)
		{
			// Check next node
			if(node->next && node->next->val == val)
			{
				// Remove next node
				node->next = node->next->next;
			}
			else
			{
				// Move node
				node = node->next;
			}
		}

		return prehead->next;
	}
};