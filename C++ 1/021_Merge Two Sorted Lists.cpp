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

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		// Root
		ListNode* preRoot = new ListNode(0);
		ListNode* nodeNew = preRoot;

		// Merge
		ListNode* node_1 = l1;
		ListNode* node_2 = l2;
		while(node_1 && node_2)
		{
			// Smaller nodes first
			if(node_1->val < node_2->val)
			{
				// node_1 is smaller
				nodeNew->next = node_1;
				node_1 = node_1->next;
			}
			else
			{
				// node_2 is smaller or the same
				nodeNew->next = node_2;
				node_2 = node_2->next;
			}

			nodeNew = nodeNew->next;
		}

		// Rest of nodes
		if(node_1)
			nodeNew->next = node_1;
		else
			nodeNew->next = node_2;

		return preRoot->next;
	}
};