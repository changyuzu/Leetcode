/*
This is a second approach that starts iterating from the last row
With this approach, we don't need to care about the edge cases of j == 0 or j == i, since the row above is bound to have less elements than the row below
So we start going from the second to last row, and for each element, we add the smaller adjacent element from the next row
More formally, we add the minimum between triangle[i+1][j] and triangle[i+1][j+1]
Then, as we move up the rows, we keep updating the minimum path sum for that row, until we finally arrive at the topmost row and return the only element
If there is only 1 row to begin with, we won't enter the for loop and return the only element as is
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size();
        for (int i = rows-2; i >= 0; i--)
        {
            for (int j = 0; j < i+1; j++) triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        }
        return triangle[0][0];
    }
};