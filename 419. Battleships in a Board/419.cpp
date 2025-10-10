/*
This problem could've been trickier, but the condition `there are no adjacent battleships` simplifies things a lot
Since there are guaranteed to be no touching battleships, you just need to count the head of a battleship
Battleships can only be placed horizontally or vertically, so they either extend in the same row or the same column
So whenever we see an 'X', if the left or upper cell in the board is also an 'X', it's part of a battleship we had seen before, so no need to count this ship
That's why we only count the head, i.e. the 'X' cells with no adjacent 'X' on its left and top
This way, we don't need any extra memory, don't need to modify the board, and only need 1 pass
*/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size(), ans = 0;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (board[i][j] == '.') continue;
                if ((j-1 < 0 || board[i][j-1] != 'X') && (i-1 < 0 || board[i-1][j] != 'X')) ans++;
            }
        }
        return ans;
    }
};