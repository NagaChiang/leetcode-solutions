#include <string>
#include <vector>

class Solution
{

public:

	std::string convert(std::string s, int numRows)
	{
		// Generate zigzag string matrix
		std::vector<std::string> matrix(numRows, std::string());
		int row = 0;
		bool isDown = true;
		for(int i = 0; i < s.length(); i++)
		{
			// Append char
			matrix[row].push_back(s[i]);

			if(numRows > 1)
			{
				// Next row
				row += isDown ? 1 : -1;

				// Change direction
				if(row == 0 || row == numRows - 1)
					isDown = !isDown;
			}
		}

		// Concatenate strings
		std::string zigzag;
		for(int i = 0; i < matrix.size(); i++)
		{
			zigzag.append(matrix[i]);
		}

		return zigzag;
	}
};