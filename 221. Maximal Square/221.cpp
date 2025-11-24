/*
This problem can be solved using DP and keeping track of the longest square side we've seen so far
The DP vector will keep track of the longest side of a valid square containing only 1's
A square is valid if its left, top, and diagonal sides have the same length, and the side for this valid square is derived from the shortest length between those three
So, for each cell in the matrix which contains '1', we do the following:
- Check whether the left, top, and diag sides are within the bounds of the matrix
	- The sides that aren't within bounds are defaulted to 0
- Fill dp[i][j] with the value of 1 + (the minimum length out of diag, left, and top)
	- We add 1 because the cell itself is 1, so at the very least, it will have the length of 1
- Check dp[i][j] against the current longest side we've seen
Note that we're keeping track of the longest LENGTH, not the area
So when we return the answer, we need to multiply the length with itself to obtain the area
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxLen = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp (m, vector<int> (n, 0));
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (matrix[i][j] == '0') continue;
                int left = 0, top = 0, diag = 0;
                if (i-1 >= 0 && j-1 >= 0)
                {
                    diag = dp[i-1][j-1];
                    top = dp[i-1][j];
                    left = dp[i][j-1];
                }
                else if (i-1 >= 0) top = dp[i-1][j];
                else if (j-1 >= 0) left = dp[i][j-1];
                dp[i][j] = 1 + min({diag, left, top});
                maxLen = max(maxLen, dp[i][j]);
                // cout << maxLen << " " << i << " " << j << " " << top << "|" << left << "|" << diag << endl;
            }
        }
        return maxLen * maxLen;
    }
};