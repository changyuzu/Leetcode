/*
This problem can be solved through backtracking
First, define the backtracking function
Start from the condition that returns false:
- row and col are out of bounds
- board[row][col] has been visited, marked with visited[row][col]
- board[row][col] isn't word[idx], the char that we're searching for
If we don't return false, that means we haven't visited this cell, and the cell contains the char we want
If idx points to the index of the last char in `word`, that means we've found the complete word, so we can return true
Otherwise, we mark the current cell as visited, and continue calling the backtracking function on neighboring cells, with index idx+1
Do note that the current iteration might not be our answer, and if that's the case, we need to mark the current cell as not-visited again
This is because another iteration might end up using the current cell to get the answer

Then, in the main function, we iterate through every cell, starting with idx = 0 to check for word[0]
If the function returns true for that cell, simply return true
If we go through all cells without finding a suitable cell, we return false
*/

class Solution {
public:
    bool backtrack(vector<vector<char>> &board, vector<vector<bool>> &visited, string &word, int row, int col, int idx, int &m, int &n, int &s)
    {
        if (row < 0 || col < 0 || row >= m || col >= n || visited[row][col] || board[row][col] != word[idx]) return false;
        if (idx == s - 1) return true;
        visited[row][col] = true;
        bool tmp = backtrack(board, visited, word, row-1, col, idx+1, m, n, s) || backtrack(board, visited, word, row+1, col, idx+1, m, n, s) || backtrack(board, visited, word, row, col-1, idx+1, m, n, s) || backtrack(board, visited, word, row, col+1, idx+1, m, n, s);
        if (!tmp) visited[row][col] = false;
        return tmp;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size(), s = word.size();
        vector<vector<bool>> visited (m, vector<bool> (n, false));
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (backtrack(board, visited, word, i, j, 0, m, n, s)) return true;
            }
        }
        return false;
    }
};