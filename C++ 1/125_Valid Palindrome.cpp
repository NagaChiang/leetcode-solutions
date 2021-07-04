#include <string>
#include <ctype.h>

// 2 Pointers
class Solution
{

public:

	bool isPalindrome(std::string s)
	{
		if(s.size() == 0)
			return true;

		int front = 0;
		int end = s.length() - 1;
		while(end > front)
		{
			// Find next valid character from the front
			while(front <= s.length() - 1 && !isalnum(s[front]))
				front++;

			// Find next valid character from the end
			while(end >= 0 && !isalnum(s[end]))
				end--;

			// Compare characters
			if(tolower(s[front]) != tolower(s[end]))
				return false;
			else
			{
				front++;
				end--;
			}
		}

		return true;
	}
};