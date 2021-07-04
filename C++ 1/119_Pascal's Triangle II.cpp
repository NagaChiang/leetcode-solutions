#include <vector>

// Math
class Solution
{

public:

	std::vector<int> getRow(int rowIndex)
	{
		if(rowIndex == 0)
		{
			std::vector<int> oneRow;
			oneRow.push_back(1);
			return oneRow;
		}

		// Using formula
		int size = rowIndex + 1;
		int center = size / 2;
		std::vector<int> row;
		row.push_back(1);
		for(int i = 1; i <= center; i++)
		{
			// Construct half row
			int num = (long)row[i - 1] * (rowIndex - i + 1) / i;
			row.push_back(num);
		}

		// Add another half by mirroring
		for(int i = size - (center + 1) - 1; i >= 0; i--)
		{
			row.push_back(row[i]);
		}

		return row;
	}
};