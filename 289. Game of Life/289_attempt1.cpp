/*
My first attempt at this problem requires extra space
Basically, I just keep track of which coordinates require changing the values in a vector called swap
If we look at the rules, only 3 of them cause the cell values to change:
- Any live cell with fewer than two live neighbors dies as if caused by under-population.
- Any live cell with more than three live neighbors dies, as if by over-population.
- Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
So, for each cell, we check all 9 neighbors to count how many are live
If we fulfill any of the above 3 conditions, we add the coordinate to our swap vector
Once we finished checking all cells, we iterate over all coordinates in swap and use XOR to flip the bit
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> dir = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        int m = board.size(), n = board[0].size();
        vector<vector<int>> swap;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                int c = 0;
                for (vector<int> &d: dir)
                {
                    int x = i+d[0], y = j+d[1];
                    if (x == m || x < 0 || y == n || y < 0) continue;
                    if (board[x][y] == 1) c++;
                }
                if ((c < 2 && board[i][j] == 1) || (c > 3 && board[i][j] == 1) || (c == 3 && board[i][j] == 0)) swap.push_back({i,j});
            }
        }
        for (vector<int> &s: swap)
        {
            int x = s[0], y = s[1];
            board[x][y] ^= 1;
        }
    }
};