/*
Weird bug, but when I'm solving this problem on 2025/10/25, the title in the problem description had the problem number listed as 55
But that's the problem number for Jump Game
And in the problem listing, the problem number for Valid Sudoku is actually 36, so that's the problem number I'm using here
Anyway, to the question
This problem is pretty much solved through brute force
We just need to keep track of whether a number has appeared in the same row, column, or sub-box multiple times
For this, we need 3 hash tables
I used three 2D vectors of size 9x9, initialized to all 0
Some may find it a bit tricky to figure out the index for the sub-box
I've defined a function called subIndex to calculate the sub-box index of a given row and column
The formula I use is basically (row subgroup) * 3 + (col subgroup) = (row/3) * 3 + (col/3)
From that formula, the resulting sub-box index would look like this on the board:
	0 1 2
	3 4 5
	6 7 8
Then it's just doing a nested for-loop for each row and column
Remember to check that the value in the grid isn't '.' before entering the rest of our checking function
Basically, if a number has appeared before on the same row, column, or sub-box, we can simply return false
Else we increment the row_count, col_count, and sub_count
If we exit the nested for-loop without encountering duplicates, we return true
*/

class Solution {
public:
    int subIndex(int &row, int &col)
    {
        return (row / 3) * 3 + (col / 3);
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row_count (9, vector<int> (9, 0));
        vector<vector<int>> col_count (9, vector<int> (9, 0));
        vector<vector<int>> sub_count (9, vector<int> (9, 0));
        for (int row=0; row<9; row++)
        {
            for (int col=0; col<9; col++)
            {
                int num = board[row][col];
                if (num == '.') continue;
                num -= '1';
                int sub = subIndex(row, col);
                // cout << row << " " << col << " " << sub << " " << board[row][col] << endl;
                if (row_count[row][num] > 0 || col_count[col][num] > 0 || sub_count[sub][num] > 0) return false;
                row_count[row][num]++;
                col_count[col][num]++;
                sub_count[sub][num]++;
            }
        }
        return true;
    }
};