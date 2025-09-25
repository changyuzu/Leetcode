/*
For this problem, we use a dynamic programming approach
This version of the code starts iterating from the first row to the last, and keeps track of the smallest sum in each row
If there is only 1 row, simply return the only element in the triangle
Otherwise, we start checking each row in the triangle
Keep in mind that we can only move to an adjacent number on the next row, so if we were on index i of row r, on row r+1, we can only go to index i or i+1
With this condition, we can define the conditions for the sums in the next row:
- If index == 0, we could only have arrived from index 0 of the previous row
- If index == the last element of the current row, we could only have arrived from the last element of the previous row
- Else, we could have arrived to our current index from index i or index i-1 of the previous row
We can modify the array triangle directly to keep track of the minimum path sum in each index, and keep track of the minimum value in minSum
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        if (rows == 1) return triangle[0][0];
        int minSum = INT_MAX;
        for (int i=1; i<rows; i++)
        {
            minSum = INT_MAX;
            for (int j=0; j<i+1; j++)
            {
                // cout << i << " " << j << " " << triangle[i][j] << endl;
                if (j == 0) triangle[i][j] += triangle[i-1][0];
                else if (j == i) triangle[i][j] += triangle[i-1][j-1];
                else triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
                minSum = min(minSum, triangle[i][j]);
            }
        }
        return minSum;
    }
};