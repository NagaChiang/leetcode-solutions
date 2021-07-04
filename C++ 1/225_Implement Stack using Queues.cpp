#include <queue>

class Stack
{
	std::queue<int> _queue;

public:

	// Push element x onto stack.
	void push(int x)
	{
		// Push and reorder size() - 1
		_queue.push(x);
		for(int i = 0; i < _queue.size() - 1; i++)
		{
			_queue.push(_queue.front());
			_queue.pop();
		}
	}

	// Removes the element on top of the stack.
	void pop()
	{
		_queue.pop();
	}

	// Get the top element.
	int top()
	{
		return _queue.front();
	}

	// Return whether the stack is empty.
	bool empty()
	{
		return _queue.empty();
	}
};