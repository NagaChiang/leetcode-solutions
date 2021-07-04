#include <string>

class Solution
{

public:

	bool repeatedSubstringPattern(std::string str)
	{
		// Try to divide the string
		for(int divide = 2; divide <= str.size(); divide++)
		{
			if(str.size() % divide == 0)
			{
				// Check
				int ptnSize = str.size() / divide;
				bool isPattern = true;
				for(int i = ptnSize, j = 0;
					i < str.size();
					i++, j = (j + 1) % ptnSize)
				{
					// Not match
					if(str[i] != str[j])
					{
						isPattern = false;
						break;
					}
				}

				// Found pattern
				if(isPattern)
					return true;
			}
		}

		return false;
	}
};

class Solution
{

public:

	bool repeatedSubstringPattern(std::string str)
	{
		// Try to divide the string
		for(int ptnSize = 1; ptnSize < str.size(); ptnSize++)
		{
			if(str.size() % ptnSize == 0)
			{
				// Check
				bool isPattern = true;
				for(int i = ptnSize, j = 0;
					i < str.size();
					i++, j = (j + 1) % ptnSize)
				{
					// Not match
					if(str[i] != str[j])
					{
						isPattern = false;
						break;
					}
				}

				// Found pattern
				if(isPattern)
					return true;
			}
		}

		return false;
	}
};