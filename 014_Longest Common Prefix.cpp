#include <vector>
#include <string>

class Solution
{

public:

	std::string longestCommonPrefix(std::vector<std::string>& strs)
	{
		// Edge cases
		if(strs.size() == 0)
			return "";
		else if(strs.size() == 1)
			return strs[0];

		// Check from the start of strings
		std::string commonPrefix = "";
		for(int i = 0;; i++)
		{
			// Check each string
			bool isSame = true;
			char common = 0;
			for(int j = 0; j < strs.size(); j++)
			{
				// Check length
				if(i < strs[j].length())
				{
					// Set reference character
					if(common <= 0)
						common = strs[j][i];
					else
					{
						// Check character
						if(strs[j][i] != common)
						{
							// Different
							isSame = false;
							break;
						}
					}
				}
				else
				{
					// Not enough length
					isSame = false;
					break;
				}
			}

			// Check same
			if(isSame)
			{
				// Append character to common prefix
				commonPrefix.push_back(common);
			}
			else
			{
				break;
			}
		}

		return commonPrefix;
	}
};