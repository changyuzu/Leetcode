/*
This question is similar to 200. Number of Islands, but we need to keep track of the area of the current island as we go
We still use a DFS function, this time called area, which returns the area of the current island
The function starts by ensuring that the row and column is within bounds, and the cell value isn't 0
If the above conditions aren't fulfilled, we return 0 (no increase in area)
Otherwise, we mark the cell as visited by modifying grid in-place and turning the cell value to 0
Then we check all 4 neighboring cells
Remember that the current cell will have an area of 1, and we just need to add the area of the neighboring cells as we go
So we can recursively call the function to get the total area by calling return 1 + (left area) + (right area) + (top area) + (bottom area)
Then, in the main function, we just need to call the area function when we encounter a cell with value 1 and update ans with the maximum area
After we finish checking all cells, we return our answer
*/

class Solution {
public:
    int area(vector<vector<int>> &grid, int row, int col, int &m, int &n)
    {
        if (row < 0 || col < 0 || row == m || col == n || grid[row][col] == 0) return 0;
        grid[row][col] = 0;
        return 1 + area(grid, row, col-1, m, n) + 
        area(grid, row, col+1, m, n) + area(grid, row-1, col, m, n) + 
        area(grid, row+1, col, m, n);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid[i][j] == 0) continue;
                int tmp = area(grid, i, j, m, n);
                ans = max(ans, tmp);
            }
        }
        return ans;
    }
};