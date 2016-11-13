#include <vector>

class Solution
{

public:

	std::vector<std::vector<int>> generate(int numRows)
	{
		std::vector<std::vector<int>> triangle;
		for(int i = 0; i < numRows; i++)
		{
			// Create row
			std::vector<int> row;
			for(int j = 0; j <= i; j++)
			{
				// First and last
				if(j == 0 || j == i)
				{
					row.push_back(1);
					continue;
				}

				// Calculate from last row
				int num = triangle[i - 1][j] + triangle[i - 1][j - 1];
				row.push_back(num);
			}

			// Push to triangle
			triangle.push_back(row);
		}

		return triangle;
	}
};