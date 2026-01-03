/*
This problem is essentially the same as 542. 01 Matrix
We need to maximize the height of the land cells, while ensuring that any two adjacent cells have an absolute height difference of at most 1
In other words, we need to find the closest water cell to a land cell
So we can use the same approach we used in Problem 542, a 2D DP
We can modify the matrix in-place so we don't need any additional space
First, we need to correctly assign the land and water cells
Since we started with the water cells as 1 and land cells as 0, and we need to make the water cells 0 in the answer, we can just flip the bits of each cell first
I did this by XOR-ing each cell with 1
Then we start our two-pass DP operation
For the first pass, we check each cell against its left and upper cells to find the closest distance to the water cells
We start the iteration from the top left corner
By default, the distance will be m + n, where m is the number of rows and n is the number of columns
But the closest water cell might be on the right or bottom cells, so we need a second pass, which checks against the right and bottom cells
The second pass will start from the bottom right corner, and needs to be checked against the original value of the land cell too
Once we've completed the second pass, we can return the isWater vector
*/

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int m = isWater.size(), n = isWater[0].size(), def = m+n;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                isWater[i][j] ^= 1;
            }
        }
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (isWater[i][j] == 0) continue;
                int top = def, left = def;
                if (i-1 >= 0) top = isWater[i-1][j];
                if (j-1 >= 0) left = isWater[i][j-1];
                isWater[i][j] = 1 + min(top, left);
            }
        }
        for (int i=m-1; i>=0; i--)
        {
            for (int j=n-1; j>=0; j--)
            {
                if (isWater[i][j] == 0) continue;
                int bot = def, right = def;
                if (i+1 < m) bot = isWater[i+1][j];
                if (j+1 < n) right = isWater[i][j+1];
                isWater[i][j] = min(isWater[i][j], 1 + min(bot, right));
            }
        }
        return isWater;
    }
};