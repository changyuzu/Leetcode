/*
This problem can be solved by keeping track of where each increment operation starts and ends on the matrix
To do this more simply, I treated each row as its own separate entity, independent of the other rows
How do we mark where the increment operation starts and ends?
For each query q in queries, q[0] is row1, q[1] is col1, q[2] is row2, q[3] is col2
We can simply increment mat[row][col1], and decrement mat[row][c2+1] only if c2+1 is within the bounds of the matrix
Then, to fill the matrix up, we check all rows, and for all columns starting from index 1, we add mat[i][j-1] to mat[i][j]
We can prove this by taking just one row as example:
n = 6, queries: {col1 = 1, col2 = 3}, {col1 = 2, col2 = 4}
Let's illustrate the steps for each query, starting from the initial state:
					row = {0, 0, 0, 0, 0, 0}
col1 = 1, col2 = 3	row = {0, 1, 0, 0,-1, 0}	->	row = {0, 1, 1, 1, 0, 0}
col1 = 2, col2 = 4	row = {0, 1, 1, 0,-1,-1}	->	row = {0, 1, 2, 2, 1, 0}
So, putting 1 at the starting point means we add 1 for all the following columns, and putting -1 at the ending point means we stop adding 1 for the following columns
Once we've checked all the queries, we then start actually filling up the matrix
For all rows from index 0 to n-1, we check the columns from index 1 to n-1, and put mat[row][col] += mat[row][col-1]
After filling up the matrix, return it and we're done
*/

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat (n, vector<int> (n, 0));
        for (vector<int> &q: queries)
        {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            for (int row = r1; row <= r2; row++)
            {
                mat[row][c1]++;
                if (c2+1 < n) mat[row][c2+1]--;
            }
        }
        for (int i=0; i<n; i++)
        {
            for (int j=1; j<n; j++) mat[i][j] += mat[i][j-1];
        }
        return mat;
    }
};