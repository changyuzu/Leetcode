/*
My first attempt had pretty good runtime, but consumed a lot of memory, due to the extra space for swap and dir
So I tried to remove those
I removed the direction vectors and used 2 more for loops instead, both going from -1 to 1
When both are 0, continue, because that's the current cell
Then, to remove swap, I changed the conditions that I'm looking at
Previously, I checked for conditions that require flipping the bit
This time, I checked for conditions that will be live in the next generation:
- Any live cell with two or three live neighbors lives on to the next generation.
- Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
We can further simplify this to:
- If there are 3 live neighbors, no matter the previous state, the cell will live in the next generation
- If a cell is live and has 2 live neighbors, it will live in the next generation
Then, I removed the swap vector by utilizing the unused int bits for each cell, since the cell value can only be 0 or 1
I used the 2nd bit to mark cells that will live on in the next generation, so we won't need extra memory anymore
But we still need 2-passes to update the board correctly
In the 2nd pass, we just shift the bits for each cell 1 bit to the right
This way, cells that will live would become 1, while the other cells would become 0
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                int c = 0;
                for (int dx = -1; dx <= 1; dx++)
                {
                    for (int dy = -1; dy <= 1; dy++)
                    {
                        if (dx == 0 && dy == 0) continue;
                        int x = i+dx, y = j+dy;
                        if (x == m || x < 0 || y == n || y < 0) continue;
                        if (board[x][y] % 2 == 1) c++;
                    }
                }
                if (c == 3 || (c == 2 && board[i][j] == 1)) board[i][j] |= 2;
            }
        }
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                board[i][j] >>= 1;
            }
        }
    }
};