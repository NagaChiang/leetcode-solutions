#include <vector>
#include <unordered_map>

class Solution
{

public:

	int numberOfBoomerangs(std::vector<std::pair<int, int>>& points)
	{
		int sum = 0;

		// For every point as center
		for(int i = 0; i < points.size(); i++)
		{
			// Distance to other points	
			std::unordered_map<int, int> mapDistance;
			for(int j = 0; j < points.size(); j++)
			{
				int dx = points[i].first - points[j].first;
				int dy = points[i].second - points[j].second;
				mapDistance[dx*dx + dy*dy]++;
			}

			// Calculate combinations
			for(auto itr = mapDistance.begin(); itr != mapDistance.end(); itr++)
			{
				int amount = itr->second;
				sum += amount * (amount - 1);
			}
		}

		return sum;
	}
};