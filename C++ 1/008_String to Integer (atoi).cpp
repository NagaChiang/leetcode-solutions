#include <string>
#include <cctype>

class Solution
{

public:

	int myAtoi(std::string str)
	{
		// Discard non-numeric characters
		int index = 0;
		for(; index < str.length(); index++)
		{
			char c = str[index];
			if(c != ' ')
				break;
		}

		// Get sign
		int sign = 1;
		if(str[index] == '+')
		{
			sign = 1;
			index++;
		}
		else if(str[index] == '-')
		{
			sign = -1;
			index++;
		}

		// Discard leading zeros
		for(; index < str.length(); index++)
		{
			if(str[index] != '0')
				break;
		}

		// Convert rest of digits
		int num = 0;
		bool hasOverflowed = false;
		for(; index < str.length(); index++)
		{
			char c = str[index];
			if(!isdigit(c))
				break;

			// Add to number and check overflow
			int nextNum = (num * 10) + (c - '0');
			if(nextNum / 10 != num)
			{
				hasOverflowed = true;
				break;
			}
			num = nextNum;
		}

		if(hasOverflowed)
			return sign > 0 ? INT_MAX : INT_MIN;
		else
			return sign * num;
	}
};