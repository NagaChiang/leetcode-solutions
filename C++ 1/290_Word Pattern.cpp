#include <string>
#include <sstream>
#include <unordered_map>

class Solution
{

public:

	bool wordPattern(std::string pattern, std::string str)
	{
		if(pattern == "" && str == "")
			return false;

		std::unordered_map<char, std::string> mapPtnWord;
		std::unordered_map<std::string, char> mapWordPtn;
		std::stringstream strStream = std::stringstream(str);
		std::string word;
		for(int i = 0; i < pattern.size(); i++)
		{
			// Get pattern and word
			char ptn = pattern[i];

			// Not enough word
			if(!(strStream >> word))
				return false;

			// Look up pattern to string map
			if(mapPtnWord.find(ptn) != mapPtnWord.end())
			{
				// Found, check mapping (pattern to word)
				if(mapPtnWord[ptn] != word)
					return false;
			}
			else
			{
				// Not found, check mapping (word to pattern)
				if(mapWordPtn.find(word) != mapWordPtn.end())
				{
					// Found (should not be)
					return false;
				}
				else
				{
					// Not found, new pattern mapping
					mapPtnWord[ptn] = word;
					mapWordPtn[word] = ptn;
				}
			}
		}

		// Too much word
		if(strStream >> word)
			return false;

		return true;
	}
};