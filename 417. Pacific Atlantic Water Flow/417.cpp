/*
For this problem, I used a dfs approach
Basically, we keep track of which cells can reach the Pacific Ocean, which cells can reach the Atlantic Ocean, and find the intersection
We can do this more easily if we start our dfs from the island's borders, which directly border the oceans, and move inward when possible
I declared 2 separate mxn boolean matrices to keep track of whether a cell can reach the Pacific or Atlantic Ocean
I also defined a helper function called fill, which does a dfs search for cells directly neighboring the current cell, whose height are equal to or higher than the current cell
The function takes the pacific and atlantic boolean 2D vectors, as well as a boolean 2D vector `curr` which could be pacific or atlantic, depending on which iteration we're checking
The purpose is to check the cells as we fill the boolean 2D vectors
So we will check the cell for curr (which is pacific or atlantic, NOT a new 2D vector)
If the current cell has been marked true, we have visited this cell before for this iteration, so we exit the function
Otherwise, we mark the current cell as true (can be reached from the ocean)
Note that this will mark the cell as true in either pacific or atlantic, NOT a new 2D vector
Then, we check if both pacific and atlantic are true for this cell
If yes, we add to our answer
Then we check the neighboring cells
If they're within bounds and their height are greater than or equal to the current cell, we call the fill function for those cells
Once we've finished the dfs search for all cells on the border, we simply return the ans vector
*/

class Solution {
public:
    void fill(vector<vector<int>> &heights, vector<vector<bool>> &pacific, vector<vector<bool>> &atlantic, vector<vector<int>> &ans, int row, int col, vector<vector<bool>> &curr, int &m, int &n)
    {
        if (curr[row][col]) return;
        curr[row][col] = true;
        if (pacific[row][col] && atlantic[row][col]) ans.push_back({row, col});
        
        if (row+1 < m && heights[row][col] <= heights[row+1][col]) fill(heights, pacific, atlantic, ans, row+1, col, curr, m, n);
        if (row-1 >= 0 && heights[row][col] <= heights[row-1][col]) fill(heights, pacific, atlantic, ans, row-1, col, curr, m, n);
        if (col+1 < n && heights[row][col] <= heights[row][col+1]) fill(heights, pacific, atlantic, ans, row, col+1, curr, m, n);
        if (col-1 >= 0 && heights[row][col] <= heights[row][col-1]) fill(heights, pacific, atlantic, ans, row, col-1, curr, m, n);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific (m, vector<bool> (n, false)), atlantic (m, vector<bool> (n, false));
        for (int i=0; i<m; i++)
        {
            fill(heights, pacific, atlantic, ans, i, 0, pacific, m, n);
            fill(heights, pacific, atlantic, ans, i, n-1, atlantic, m, n);
        }
        for (int i=0; i<n; i++)
        {
            fill(heights, pacific, atlantic, ans, 0, i, pacific, m, n);
            fill(heights, pacific, atlantic, ans, m-1, i, atlantic, m, n);
        }
        return ans;
    }
};