#include <string>
#include <vector>
#include <arrat>

// Iterative
// 3 ms
class Solution
{

public:

	std::vector<std::string> readBinaryWatch(int num)
	{
		std::vector<std::string> times;
		for(int hour = 0; hour < 12; hour++)
		{
			for(int minute = 0; minute < 60; minute++)
			{
				// Count bits
				int numBit = countBits((hour << 6) + minute);
				if(numBit == num)
					times.push_back(toTimeString(hour, minute));
			}
		}

		return times;
	}

private:

	int countBits(int n)
	{
		int clone = n;
		int count = 0;
		while(clone > 0)
		{
			count += clone & 1;
			clone >>= 1;
		}

		return count;
	}

	std::string toTimeString(int hour, int minute)
	{
		std::string strHour = std::to_string(hour);
		std::string strMinute = std::to_string(minute);

		// Leading zero of minute
		if(strMinute.length() < 2)
			strMinute = "0" + strMinute;

		return strHour + ":" + strMinute;
	}
};