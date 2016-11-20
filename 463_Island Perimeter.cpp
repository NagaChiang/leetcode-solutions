#include <vector>

// DFS
class Solution
{

public:

	int islandPerimeter(std::vector<std::vector<int>>& grid)
	{
		// Find any island
		int sum = 0;
		for(int i = 0; i < grid.size(); i++)
		{
			for(int j = 0; j < grid[0].size(); j++)
			{
				if(grid[i][j] == 1)
				{
					sum = countPerimeter(grid, i, j);
					break;
				}
			}
		}

		return sum;
	}

private:

	int countPerimeter(std::vector<std::vector<int>>& grid, int x, int y)
	{
		int maxX = grid.size() - 1;
		int maxY = grid[0].size() - 1;
		
		// Check valid
		if(x < 0 || x > maxX
			|| y < 0 || y > maxY
			|| grid[x][y] != 1)
		{
			return 0;
		}

		// Mark as visited
		grid[x][y] = -1;

		// Count
		int sum = 0;
		sum += (x + 1 > maxX || grid[x + 1][y] == 0);
		sum += (x - 1 < 0 || grid[x - 1][y] == 0);
		sum += (y + 1 > maxY || grid[x][y + 1] == 0);
		sum += (y - 1 < 0 || grid[x][y - 1] == 0);

		// DFS
		sum += countPerimeter(grid, x + 1, y);
		sum += countPerimeter(grid, x, y + 1);
		sum += countPerimeter(grid, x - 1, y);
		sum += countPerimeter(grid, x, y - 1);

		return sum;
	}
};

// O(mn)
class Solution
{

public:

	int islandPerimeter(std::vector<std::vector<int>>& grid)
	{
		int sum = 0;
		for(int i = 0; i < grid.size(); i++)
		{
			for(int j = 0; j < grid[0].size(); j++)
			{
				if(grid[i][j] == 1)
				{
					sum += checkPerimeter(grid, i + 1, j);
					sum += checkPerimeter(grid, i, j + 1);
					sum += checkPerimeter(grid, i - 1, j);
					sum += checkPerimeter(grid, i, j - 1);
				}
			}
		}

		return sum;
	}

private:

	int checkPerimeter(std::vector<std::vector<int>>& grid, int x, int y)
	{
		int maxX = grid.size() - 1;
		int maxY = grid[0].size() - 1;
		if(x >= 0 && x <= maxX && y >= 0 && y <= maxY)
		{
			if(grid[x][y] == 1)
				return 0;
			else
				return 1;
		}
		else
		{
			return 1;
		}
	}
};