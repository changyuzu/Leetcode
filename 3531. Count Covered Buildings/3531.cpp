/*
To solve this problem, we just need to keep track of the first and last elements of each row and column
For a building to be covered, we just need to ensure that it isn't at the edge of its row AND column
As long as a building isn't on the edge of its row and column, there's guaranteed to be at least one building on its left, right, top, and bottom
To accomplish this, I used 4 separate vectors, all with size n+1 since the x-y coordinates are in the range of [1..n]
- minRow and minCol keep track of the minimum values of each row and column respectively, each element initialized to n+1 since we will check for the minimum between the current value and the new elements
- maxRow and maxCol keep track of the maximum values of each row and column respectively
Then, we will need 2 for loops
The first one is just to update the min and max for each row and column using the existing buildings
The second one will check each building against each min and max of their respective row and column
If a building's x and y coordinates aren't the min and max of its row and column, then it's covered, and we increment our answer
Once we've finished the second for loop, return the answer
*/

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> minRow (n+1, n+1);
        vector<int> maxRow (n+1);
        vector<int> minCol (n+1, n+1);
        vector<int> maxCol (n+1);
        for (vector<int> &b: buildings)
        {
            const int x = b[0], y = b[1];
            minRow[y] = min(x, minRow[y]);
            maxRow[y] = max(x, maxRow[y]);
            minCol[x] = min(y, minCol[x]);
            maxCol[x] = max(y, maxCol[x]);
        }
        int ans = 0;
        for (vector<int> &b: buildings)
        {
            const int x = b[0], y = b[1];
            if (x == minRow[y] || x == maxRow[y] || y == minCol[x] || y == maxCol[x]) continue;
            ans++;
        }
        return ans;
    }
};