/*
This question can be solved by simply keeping track of the highest neededTime for each consecutive colors
We don't have any rule about the index that needs to be kept for the consecutive colors, which makes things easier
For each consecutive colors, just keep track of the highest neededTime seen for that color, while adding the lesser values to our time counter
If we encounter a different color, reset the highest neededTime to the neededTime of the current color
The `curr` variable tracks the highest neededTime for the current color (initialized to neededTime[0], for the first color), while `ans` is our time counter
Starting from index i=1, we check if the current color is the same as the previous one
If not, set `curr` to the current color's neededTime
Otherwise, check if neededTime[i] is higher than the current highest neededTime
- If yes, add `curr` (the previous highest neededTime) to ans and set curr to neededTime[i]
- Otherwise, add neededTime[i] to ans
Once we've reached index i = n-1, return ans
*/

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), curr = neededTime[0], ans = 0;
        for (int i=1; i<n; i++)
        {
            if (colors[i] != colors[i-1]) curr = neededTime[i];
            else
            {
                if (neededTime[i] > curr)
                {
                    ans += curr;
                    curr = neededTime[i];
                }
                else ans += neededTime[i];
            }
        }
        return ans;
    }
};