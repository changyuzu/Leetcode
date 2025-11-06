/*
My first attempt is more like a brute-force
I'll attempt a Union-Find solution tomorrow, maybe
But in this attempt, I used a few data structures to store the information
- vector of set of integer, to keep track of each power grid
- vector of vector of integer, for the adjacency list of the graph from the power grid
- vector of bool, to keep track of visited nodes in the dfs function, and later reused to keep track of whether a grid is online
- unordered_map of int and int, to keep track of the grid index
Basically, I create different graphs for each power grid, which are each stored as a set
Storing the power grid as a set allows us to quickly obtain the smallest elements
But we also need to be able to quickly find the grid where the power station belongs, which is where the unordered_map comes in
So, we first start by filling up the grids and grid indexes with the dfs function
Then, we start checking the queries
- If q[0] == 2, mark the station as offline and remove the station from its corresponding grid
- Else, check if the station is online
	- If the station is online, simply add the station to our answer
	- Else, check if the station's corresponding grid is empty
		- If the power grid is empty, add -1 to our answer
		- Otherwise, add the first element of the power grid's set to our answer
Once we've checked all the queries, return the answer vector
*/

class Solution {
public:
    void dfs(vector<vector<int>> &adjList, set<int> &grid, vector<bool> &visited, unordered_map<int, int> &gridIdx, int &idx, int station)
    {
        if (visited[station]) return;
        visited[station] = true;
        grid.insert(station);
        gridIdx[station] = idx;
        for (int &neighbor: adjList[station]) dfs(adjList, grid, visited, gridIdx, idx, neighbor);
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<set<int>> grids;
        vector<vector<int>> adjList (c+1);
        vector<bool> visited (c+1, false);
        vector<int> ans;
        unordered_map<int, int> gridIdx;
        for (vector<int> &c: connections)
        {
            adjList[c[0]].push_back(c[1]);
            adjList[c[1]].push_back(c[0]);
        }
        int idx = 0;
        for (int i=1; i<=c; i++)
        {
            if (visited[i]) continue;
            set<int> grid;
            dfs(adjList, grid, visited, gridIdx, idx, i);
            grids.push_back(grid);
            idx++;
        }
        for (vector<int> &q: queries)
        {
            if (q[0] == 2)
            {
                visited[q[1]] = false;
                grids[gridIdx[q[1]]].erase(q[1]);
            }
            else
            {
                if (visited[q[1]]) ans.push_back(q[1]);
                else
                {
                    if (!grids[gridIdx[q[1]]].empty()) ans.push_back(*grids[gridIdx[q[1]]].begin());
                    else ans.push_back(-1);
                }
            }
        }
        return ans;
    }
};