/*
This problem can be solved with a two-pass DP approach
We can modify the matrix mat in place, so there will be no need for additional space
So, we'll need two passes over the array:
- The first one starts from the top left corner, and we check each non-zero cell against its left and top cells
	- If the left or top cells were out of bounds, assign them as 0
	- Otherwise, we assign the actual values of the left and top cells
	- Each iteration updates the closest distance to a 0 through a cell's left or top cell
		- Since the current iteration adds the current cell to the distance, the actual value of mat[i][j] becomes 1 + min(top, left)
- The second pass does pretty much the same thing, but starting from the bottom right corner
	- We do this because the closest 0 to a cell might be on the bottom right side instead of the top left
	- So, in addition to checking the right and bottom cells, we also need to check against the original value of mat[i][j], which would be the closest distance to the top-left 0's
Once we've finished both iterations, return the updated matrix mat
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size(), maxDist = m+n;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (mat[i][j] == 0) continue;
                int left = maxDist, top = maxDist;
                if (j-1 >= 0) left = mat[i][j-1];
                if (i-1 >= 0) top = mat[i-1][j];
                mat[i][j] = 1 + min(top, left);
            }
        }
        for (int i=m-1; i>=0; i--)
        {
            for (int j=n-1; j>=0; j--)
            {
                if (mat[i][j] == 0) continue;
                int right = maxDist, down = maxDist;
                if (j+1 < n) right = mat[i][j+1];
                if (i+1 < m) down = mat[i+1][j];
                mat[i][j] = min(mat[i][j], 1 + min(down, right));
            }
        }
        return mat;
    }
};