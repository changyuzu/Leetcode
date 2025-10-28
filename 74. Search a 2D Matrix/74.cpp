/*
My approach does 2 layers of binary search:
- Search the first element of the row to find a row where row[0] <= target <= row[n-1]
- Search for the element in that row
If we're unable to find a row which fulfills the first condition, we return false
But if we could find a row with the given constraint, and weren't able to find the target in that row, we also return false
Return true only if we could actually locate the target element
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), row_l = 0, row_r = m-1;
        while (row_l <= row_r)
        {
            int m = row_l + (row_r - row_l) / 2;
            if (matrix[m][0] > target) row_r = m-1;
            else
            {
                if (matrix[m][n-1] < target) row_l = m+1;
                else
                {
                    int col_l = 0, col_r = n-1;
                    while (col_l <= col_r)
                    {
                        int col_m = col_l + (col_r - col_l) / 2;
                        if (matrix[m][col_m] >= target) col_r = col_m - 1;
                        else col_l = col_m + 1;
                    }
                    // cout << m << " " << col_l << endl;
                    if (matrix[m][col_l] == target) return true;
                    else return false;
                }
            }
        }
        return false;
    }
};