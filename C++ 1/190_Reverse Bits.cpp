#include <stdint.h>

class Solution
{

public:

	uint32_t reverseBits(uint32_t n)
	{
		int reversed[16] = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
		int result = 0;
		int mask = 0xF;
		for(int i = 0; i < 8; i++)
		{
			result <<= 4;
			result |= reversed[mask & n];
			n >>= 4;
		}

		return result;
	}
};