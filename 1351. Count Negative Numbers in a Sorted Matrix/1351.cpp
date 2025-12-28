/*
This problem can just be solved with brute force, since the constraints of the matrix size is limited to 100 * 100
In a fixed row, if an element turns to negative, all next elements in the same row will be negative
In the same way, if the first element of a row turns to negative, all elements in the next rows will also be negative
But if the last element of a row is still a positive number, no negative elements exist in that row, so we can skip that row
So, with m = number of rows, n = number of columns, we can write the following algorithm:
For row i in the range [0..m]:
- If the first element of a row is negative, the current row and all following rows will be negative
	ans += (m-1) * n
- If the last element isn't negative, there is no negative element in this row, so we skip to the next row
- Otherwise, the negative elements start in the middle, so we find the index of the first negative element
	- For column j in the range [0..n]:
		- If grid[i][j] is negative, all elements after it in this row is also negative, and we can stop checking this row
			ans += n-j
Once we've finished checking, return our answer
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i=0; i<m; i++)
        {
            if (grid[i][0] < 0)
            {
                ans += (m-i) * n;
                break;
            }
            else if (grid[i][n-1] > 0) continue;
            for (int j=0; j<n; j++)
            {
                if (grid[i][j] < 0)
                {
                    ans += n - j;
                    break;
                }
            }
        }
        return ans;
    }
};