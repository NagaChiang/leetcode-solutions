#include <string>

class Solution
{

public:

	std::string toHex(int num)
	{
		char hexs[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

		// 0
		if(num == 0)
			return "0";

		// Convert
		std::string strHex = "";
		const int mask = 0xf; // 1111
		for(int i = 0; i < 8; i++)
		{
			// Mask out last 4 bits
			int bits = num & mask;
			strHex.insert(strHex.begin(), hexs[bits]);
			num >>= 4;
		}

		// No leading zeros
		while(strHex.size() > 1 && strHex.front() == '0')
			strHex.erase(0, 1);

		return strHex;
	}
};