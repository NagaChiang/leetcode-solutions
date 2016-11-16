#include <stack>

class Queue
{

	std::stack<int> _stack;

public:

	// Push element x to the back of queue.
	void push(int x)
	{
		_stack.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void)
	{
		// Pop until the last element
		std::stack<int> stackTemp;
		while(_stack.size() > 1)
		{
			stackTemp.push(_stack.top());
			_stack.pop();
		}

		// Remove the last element
		_stack.pop();

		// Put elements back
		while(!stackTemp.empty())
		{
			_stack.push(stackTemp.top());
			stackTemp.pop();
		}
	}

	// Get the front element.
	int peek(void)
	{
		// Pop until the last element
		std::stack<int> stackTemp;
		while(_stack.size() > 1)
		{
			stackTemp.push(_stack.top());
			_stack.pop();
		}

		// Keep the last element
		int front = _stack.top();

		// Put elements back
		while(!stackTemp.empty())
		{
			_stack.push(stackTemp.top());
			stackTemp.pop();
		}

		return front;
	}

	// Return whether the queue is empty.
	bool empty(void)
	{
		return _stack.empty();
	}
};