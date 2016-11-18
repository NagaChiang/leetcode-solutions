#include <vector>
#include <ctype.h>

class Solution
{

public:

	bool isValidSudoku(std::vector<std::vector<char>>& board)
	{
		const int OFFSET = '1';

		// Check horizontal lines
		for(int row = 0; row < 9; row++)
		{
			bool hasNums[9] = { false };
			for(int col = 0; col < 9; col++)
			{
				int num = board[row][col];
				if(isdigit(num) && num != 0)
				{
					if(hasNums[num - OFFSET])
						return false;
					else
						hasNums[num - OFFSET] = true;
				}
			}
		}

		// Check vertical lines
		for(int col = 0; col < 9; col++)
		{
			bool hasNums[9] = { false };
			for(int row = 0; row < 9; row++)
			{
				int num = board[row][col];
				if(isdigit(num) && num != 0)
				{
					if(hasNums[num - OFFSET])
						return false;
					else
						hasNums[num - OFFSET] = true;
				}
			}
		}

		// Check 9 set of grids
		for(int row = 0; row < 9; row += 3)
		{
			for(int col = 0; col < 9; col += 3)
			{
				bool hasNums[9] = { false };
				for(int i = 0; i < 3; i++)
				{
					for(int j = 0; j < 3; j++)
					{
						int num = board[row + i][col + j];
						if(isdigit(num) && num != 0)
						{
							if(hasNums[num - OFFSET])
								return false;
							else
								hasNums[num - OFFSET] = true;
						}
					}
				}
			}
		}

		return true;
	}
};