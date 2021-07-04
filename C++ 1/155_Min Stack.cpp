#include <limits>
#include <stack>

class MinStack
{

	std::stack<int> _stack;
	std::stack<int> _stackMin;

public:
	
	MinStack()
	{
		
	}

	void push(int x)
	{
		_stack.push(x);

		// Push the min of current stack to stackMin
		if(_stackMin.empty())
			_stackMin.push(x);
		else
		{
			if(x <= _stackMin.top())
				_stackMin.push(x);
		}
	}

	void pop()
	{
		if(_stack.top() == _stackMin.top())
			_stackMin.pop();

		_stack.pop();
	}

	int top()
	{
		return _stack.top();
	}

	int getMin()
	{
		if(!_stackMin.empty())
			return _stackMin.top();
		else
			return -1;
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack obj = new MinStack();
* obj.push(x);
* obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.getMin();
*/