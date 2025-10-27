/*
To solve this problem using constant space, we can use the first row and column to keep track of whether there is any 0 in that row / column
But first, we need to check whether the first row and column initially had any zeroes
We can keep track of those with 2 boolean variables, and check only the first row and the first column at first
Then, for the rest of the cell, we start checking from row = 1 and col = 1
If matrix[row][col] == 0, mark matrix[0][col] and matrix[row][0] as 0
Then we start filling the zeroes, also starting from row = 1 and col = 1
Afterwards, check whether we initially had any zeroes in the first row and column
If yes, we fill the first row / column with zeroes too
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowZero = false, colZero = false; // whether the first row / column has 0
        int m = matrix.size(), n = matrix[0].size();
        for (int row=0; row<m; row++)
        {
            if (matrix[row][0] == 0)
            {
                colZero = true;
                break;
            }
        }
        for (int col=0; col<n; col++)
        {
            if (matrix[0][col] == 0)
            {
                rowZero = true;
                break;
            }
        }
        for (int row=1; row<m; row++)
        {
            for (int col=1; col<n; col++)
            {
                if (matrix[row][col] == 0)
                {
                    matrix[0][col] = 0;
                    matrix[row][0] = 0;
                }
            }
        }
        // for (vector<int> &row: matrix)
        // {
        //     for (int &col: row) cout << col << " ";
        //     cout << endl;
        // }
        for (int row=1; row<m; row++)
        {
            if (matrix[row][0] != 0) continue;
            for (int col=1; col<n; col++) matrix[row][col] = 0;
        }
        for (int col=1; col<n; col++)
        {
            if (matrix[0][col] != 0) continue;
            for (int row=1; row<m; row++) matrix[row][col] = 0;
        }
        if (rowZero) for (int col=0; col<n; col++) matrix[0][col] = 0;
        if (colZero) for (int row=0; row<m; row++) matrix[row][0] = 0;
    }
};