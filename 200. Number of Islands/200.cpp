/*
This problem can be solved with simple DFS
So whenever we encounter a land (cell of '1') we increment the island count, then mark that cell as well as all neighboring cells as read
In order to save memory, I just modified the grid in place by changing '1' into '0'
So, I created a helper function called dfs
It starts by checking that the row and col coordinates are within bounds, and the cell value isn't 0
If the above conditions aren't fulfilled, we simply return
Otherwise, we mark that cell as '0', then call the function on all 4 neighboring cells
Once all cells have been checked, we return the island count
*/

class Solution {
public:
    void dfs(vector<vector<char>> &grid, int row, int col, int &m, int &n)
    {
        if (row < 0 || col < 0 || row == m || col == n || grid[row][col] == '0') return;
        grid[row][col] = '0';
        dfs(grid, row-1, col, m, n);
        dfs(grid, row+1, col, m, n);
        dfs(grid, row, col-1, m, n);
        dfs(grid, row, col+1, m, n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid[i][j] == '0') continue;
                ans++;
                dfs(grid, i, j, m, n);
            }
        }
        return ans;
    }
};