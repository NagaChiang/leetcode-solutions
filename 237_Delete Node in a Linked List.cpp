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

	void deleteNode(ListNode* node)
	{
		node->val = node->next->val;
		node->next = node->next->next;
	}
};

// Memory copy
class Solution
{

public:

	void deleteNode(ListNode* node)
	{
		memcpy(node, node->next, sizeof(ListNode));
	}
};