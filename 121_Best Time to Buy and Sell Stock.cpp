#include <limits>
#include <vector>

// Greedy
class Solution
{

public:

	int maxProfit(std::vector<int>& prices)
	{
		int minPrice = std::numeric_limits<int>().max();
		int maximumProfit = 0;
		for(int i = 0; i < prices.size(); i++)
		{
			// Min price
			if(prices[i] < minPrice)
				minPrice = prices[i];

			// Max profit
			int profit = prices[i] - minPrice;
			if(profit > maximumProfit)
				maximumProfit = profit;
		}

		return maximumProfit;
	}
};