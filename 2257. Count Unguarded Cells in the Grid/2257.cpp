/*
This problem can be solved using DFS and simulating the grid
Start by declaring an empty grid, then fill it with the positions of the guards and walls
We also have a counter, which is initialized to m*n, and needs to be DECREMENTED for each GUARD and WALL
Then, for each guard, we need to run a DFS function which marks the cells in its 4 directions as guarded, when unobstructed by walls or other guards
To do this, I declared a helper function called check, which does DFS over cells in set directions
The function takes the grid, the counter, the row and column, the grid size, and two separate integers, dr and dc
dr denotes the row direction, and dc denotes the column direction
Having these 2 separate variables makes it easier to move to the next iteration
Start by declaring the conditions where we stop iterating:
- row and col go out of bounds
- grid[row][col] is either a wall or a guard, which obstructs the current guard's vision
If we've confirmed that the current cell is still valid and can be guarded, we check if it has been marked before
If the cell hasn't been marked as guarded, we mark is as guarded, and decrement our counter
This prevents counting the same cell as guarded twice
Then we call the function on the next cell, which would be at coordinate row+dr and col+dc
Once we've checked all the guards, simply return the counter
*/

class Solution {
public:
    void check(vector<vector<char>> &grid, int &count, int row, int col, int dr, int dc, int &m, int &n)
    {
        // cout << row << " " << col << " " << dr << " " << dc << endl;
        if (row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 'W' || grid[row][col] == 'G') return;
        if (grid[row][col] == '.')
        {
            count--;
            grid[row][col] = 'X';
        }
        // cout << "Marked " << row << " " << col << endl;
        check(grid, count, row+dr, col+dc, dr, dc, m, n); // neighbor cell
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<char>> grid(m, vector<char> (n, '.'));
        int count = m*n;
        for (vector<int> &guard: guards)
        {
            count--;
            grid[guard[0]][guard[1]] = 'G';
        }
        for (vector<int> &wall: walls)
        {
            count--;
            grid[wall[0]][wall[1]] = 'W';
        }
        for (vector<int> &guard: guards)
        {
            int row = guard[0], col = guard[1];
            check(grid, count, row-1, col, -1, 0, m, n);
            check(grid, count, row+1, col, 1, 0, m, n);
            check(grid, count, row, col-1, 0, -1, m, n);
            check(grid, count, row, col+1, 0, 1, m, n);
        }
        // for (vector<char> &row: grid)
        // {
        //     for (char &c: row) cout << c << " ";
        //     cout << endl;
        // }
        return count;
    }
};