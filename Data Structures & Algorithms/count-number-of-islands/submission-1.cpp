class Solution {
public:
    // Iterative DFS search
    void gridSearch(vector<vector<char>>& grid, int row, int col)
    {
        stack<pair<int, int>> islandCells;
        islandCells.push({row, col});

        while (!islandCells.empty())
        {
            pair<int,int> currCell = islandCells.top();
            islandCells.pop();
            
            for (pair<int,int> dir: dirs)
            {
                int newRow = currCell.first + dir.first;
                int newCol = currCell.second + dir.second;

                if (0 <= newRow && newRow < rows &&
                    0 <= newCol && newCol < cols &&
                    grid[newRow][newCol] == '1')
                {
                    grid[newRow][newCol] = '0';
                    islandCells.push({newRow, newCol});
                }
            }
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

private:
    int rows;
    int cols;
    vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {-1,0}, {1,0}};
};