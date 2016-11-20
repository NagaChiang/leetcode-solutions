#include <string>
#include <stack>

class Solution
{

public:

	bool isValid(std::string s)
	{
		std::stack<char> stackChar;
		for(int i = 0; i < s.length(); i++)
		{
			char c = s[i];
			if(c == '(' || c == '[' || c == '{')
			{
				// Start
				stackChar.push(c);
			}
			else if(c == ')' || c == ']' || c == '}')
			{
				// End
				if(!stackChar.empty())
				{
					// Check
					char top = stackChar.top();
					if((top == '(' && c == ')')
						|| (top == '[' && c == ']')
						|| (top == '{' && c == '}'))
					{
						// Pop
						stackChar.pop();
					}
					else
					{
						// Invalid
						return false;
					}
				}
				else
				{
					// Empty stack
					return false;
				}
			}
		}

		// Stack is stiil not empty
		if(!stackChar.empty())
		{
			return false;
		}

		return true;
	}
};