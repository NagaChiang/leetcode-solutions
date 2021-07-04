#include <string>
#include <math.h>

class Solution
{

public:

	int titleToNumber(std::string s)
	{
		const int NUM_ALPHABET = 26;
		int num = 0;
		for(int i = 0; i < s.length(); i++)
		{
			int index = s.length() - i - 1;
			num += alphabetToNumber(s[index]) * pow(NUM_ALPHABET, i);
		}

		return num;
	}

private:

	int alphabetToNumber(char c)
	{
		return c - 'A' + 1;
	}
};