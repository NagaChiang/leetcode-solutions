#include <vector>

class Solution
{

public:

	std::vector<int> plusOne(std::vector<int>& digits)
	{
		if(digits.size() == 0)
			return digits;

		// Add 1
		digits[digits.size() - 1]++;

		// Adder
		int carry = 0;
		for(int i = digits.size() - 1; i >= 0; i--)
		{
			int c = carry;
			int digit = digits[i];
			digits[i] = (digit + c) % 10;
			carry = (digit + c) / 10;

			if(carry == 0)
				break;
		}

		// Need one more digit
		if(carry > 0)
			digits.insert(digits.begin(), carry);

		return digits;
	}
};