#include <string>
#include <sstream>

class Solution
{

public:

	int lengthOfLastWord(std::string s)
	{
		std::stringstream stream = std::stringstream(s);
		std::string word;
		int lastLength = 0;
		while(stream >> word)
		{
			lastLength = word.length();
		}

		return lastLength;
	}
};