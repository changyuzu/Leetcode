/*
For this problem, we need to keep track of 2 things:
- The number of fresh oranges
- The oranges that get rotten in any given minute
I originally thought of using DFS, as seen in the rotTime function defined below
The plan was to call the function on all cells adjacent to rotten oranges, and return 1 + (whether the surroundings have any fresh oranges turned rotten)
The function will continue to call itself whenever there's any adjacent fresh orange
My approach worked, but only for cases where there is only 1 rotten orange
When I saw my code failing for this test case, I realized BFS is the way to go
	grid = [[2,2],[1,1],[0,0],[2,0]]
DFS returns 2, but the rotting process happens for all 4-directionally adjacent oranges at the same time
So the 2 fresh oranges in row 1 should rot at the same time since both are adjacent to rotten oranges
Therefore, I retried using BFS
The first pass over all elements of the grid keeps track of the number of fresh oranges, and the positions of the rotten oranges
We push the coordinates of the rotten oranges into a queue
Check if there are any fresh oranges, if not, simply return 0
Otherwise, we start the BFS on the queue elements:
- Get the location of the rotten oranges in the current iteration
- Push the location of their neighbors into the queue, decrement the number of fresh oranges, and mark those neighbors as rotten
- When this iteration is done, increment time, and continue to the next iteration
Do note that we start counting time from -1 instead of 0, since the first iteration will also increment our time
Once we've checked all fresh oranges that are adjacent to rotten oranges, check whether there are still fresh oranges which haven't rotten
If there are, return -1, otherwise return the elapsed time
*/

class Solution {
public:
#define pii pair<int, int>
    int rotTime(vector<vector<int>> &grid, int row, int col, int &fresh, int &m, int &n)
    {
        // cout << row << " " << col << endl;
        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != 1) return 0;
        grid[row][col] = 2;
        fresh--;
        return 1 + (rotTime(grid, row, col-1, fresh, m, n) | rotTime(grid, row, col+1, fresh, m, n) | rotTime(grid, row-1, col, fresh, m, n) | rotTime(grid, row+1, col, fresh, m, n));
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0, m = grid.size(), n = grid[0].size(), time = -1;
        queue<pii> q;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) q.push({i, j});
            }
        }
        if (fresh == 0) return 0;
        while (!q.empty())
        {
            int s = q.size();
            time++;
            while (s--)
            {
                int row = q.front().first, col = q.front().second;
                q.pop();
                if (row-1 >= 0 && grid[row-1][col] == 1)
                {
                    grid[row-1][col] = 2;
                    q.push({row-1, col});
                    fresh--;
                }
                if (row+1 < m && grid[row+1][col] == 1)
                {
                    grid[row+1][col] = 2;
                    q.push({row+1, col});
                    fresh--;
                }
                if (col-1 >= 0 && grid[row][col-1] == 1)
                {
                    grid[row][col-1] = 2;
                    q.push({row, col-1});
                    fresh--;
                }
                if (col+1 < n && grid[row][col+1] == 1)
                {
                    grid[row][col+1] = 2;
                    q.push({row, col+1});
                    fresh--;
                }
            }
        }
        return (fresh == 0) ? time : -1;
    }
};