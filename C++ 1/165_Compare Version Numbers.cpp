#include <string>

class Solution
{

public:

	int compareVersion(std::string version1, std::string version2)
	{
		int result = 0;

		// Compare version numbers
		while(!version1.empty() || !version2.empty())
		{
			int ver1 = getVersion(version1);
			int ver2 = getVersion(version2);
			if(ver1 > ver2)
			{
				result = 1;
				break;
			}
			else if(ver2 > ver1)
			{
				result = -1;
				break;
			}
		}
		
		return result;
	}

	// Remove characters until dot
	int getVersion(std::string& ver)
	{
		std::string num;
		for(int i = 0; i < ver.length();)
		{
			char c = ver[i];
			ver.erase(ver.begin());

			if(c == '.')
				break;

			num.push_back(c);
		}

		return num.empty() ? 0 : std::stoi(num);
	}
};