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

	ListNode* deleteDuplicates(ListNode* head)
	{
		ListNode* node = head;
		while(node && node->next)
		{
			if(node->val == node->next->val)
			{
				ListNode* nextNode = node->next;
				node->next = node->next->next;
				free(nextNode);
			}
			else
			{
				node = node->next;
			}
		}

		return head;
	}
};