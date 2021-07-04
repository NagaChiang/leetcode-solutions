#include <string>

class Solution
{

public:

	std::string addBinary(std::string a, std::string b)
	{
		std::string ans;
		int carry = 0;
		for(int i = a.length() - 1, j = b.length() - 1;
			i >= 0 || j >= 0 || carry > 0;
			i--, j--)
		{
			int bit1 = i >= 0 && a[i] == '1' ? 1 : 0;
			int bit2 = j >= 0 && b[j] == '1' ? 1 : 0;
			int sum = bit1 + bit2 + carry;
			carry = 0;
			if(sum == 3)
			{
				ans.insert(ans.begin(), '1');
				carry = 1;
			}
			else if(sum == 2)
			{
				ans.insert(ans.begin(), '0');
				carry = 1;
			}
			else if(sum == 1)
			{
				ans.insert(ans.begin(), '1');
				carry = 0;
			}
			else if(sum == 0)
			{
				ans.insert(ans.begin(), '0');
				carry = 0;
			}
		}

		return ans;
	}
};