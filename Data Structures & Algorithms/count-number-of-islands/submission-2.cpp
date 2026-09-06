class Solution {
private:
    int rows;
    int cols;

public:
    // Recursive DFS search
    void gridSearch(vector<vector<char>>& grid, int row, int col)
    {
        grid[row][col] = '0';

        if (row + 1 < rows && grid[row + 1][col] == '1')
        {
            gridSearch(grid, row + 1, col);
        }

        if (0 <= row - 1 && grid[row - 1][col] == '1')
        {
            gridSearch(grid, row - 1, col);
        }

        if (col + 1 < cols && grid[row][col + 1] == '1')
        {
            gridSearch(grid, row, col + 1);
        }

        if (0 <= col - 1 && grid[row][col - 1] == '1')
        {
            gridSearch(grid, row, col - 1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int numIslands = 0;

        for (int row = 0; row < rows; ++row)
        {
            for (int col = 0; col < cols; ++col)
            {
                if (grid[row][col] == '1')
                {
                    ++numIslands;
                    gridSearch(grid, row, col);
                }
            }
        }

        return numIslands;
    }
};