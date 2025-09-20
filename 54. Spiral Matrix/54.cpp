/*
For this problem, we need to keep track of which direction we're going next from any given cell
To make things easier, we mark the cells we've visited, so whenever we go out of bounds or encounter a visited cell, we know to change directions
We can use another matrix to do this, or save memory by simply changing the value in the matrix in-place to some value which won't appear in the specified constraints
The problem statement specifically says `-100 <= matrix[i][j] <= 100`, so any value above 100 will do, but I used INT_MAX in the code
What's left is keeping track of the direction we should go
We can initialize the directions we should go for the row and column as variables named dx and dy
For each iteration, we move from matrix[row][col] to matrix[row + dx][col + dy]
We know that going to the right is (row+0, col+1), down is (row+1, col+0), left is (row+0, col-1), up is (row-1, col+0)
We can see that whenever we move direction, the dx and dy values change following this formula:
	dx = dy
	dy = -dx
So, for each iteration, we check whether the next cell is out of bounds or visited
If yes, we change the values of dx and dy as specified above
Then we move to the next cell
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dx = 0, dy = 1, row = 0, col = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> ans;
        for (int i=0; i < m*n; i++)
        {
            // cout << row << " " << col << endl;
            ans.push_back(matrix[row][col]);
            matrix[row][col] = INT_MAX;
            if (row + dx == m || row + dx < 0 || col + dy == n || col + dy < 0 || matrix[row+dx][col+dy] == INT_MAX)
            {
                int tmp = dx;
                dx = dy;
                dy = -tmp;
            }
            row += dx;
            col += dy;
        }
        return ans;
    }
};