#include <string>

// Better
class Solution
{

public:

	std::string convertToTitle(int n)
	{
		std::string title;
		while(n > 0)
		{
			n--;
			title.insert(title.begin(), n % 26 + 'A');
			n /= 26;
		}

		return title;
	}
};

class Solution
{

public:

	std::string convertToTitle(int n)
	{
		char toChar[26] = { 'Z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
							'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
							'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y' };
		std::string title;
		while(n > 0)
		{
			int num = n % 26;
			title.insert(title.begin(), toChar[num]);
			n /= 26;

			// For Z
			if(num == 0)
				n--;
		}

		return title;
	}
};