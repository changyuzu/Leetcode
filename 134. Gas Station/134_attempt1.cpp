/*
My first attempt utilizes dynamic programming
The dp array keeps track of the difference between the gas and cost
We fill the dp as we go and keep track of how much gas is in the tank at any given station
I declared a variable tank, to keep track of how much gas is currently in the tank, and idx, which will be updated with the temporary answer
If the tank falls below 0, we know the current index isn't the answer, so we reset the tank to 0
Otherwise, if idx hasn't been set (idx == -1), we set the current index as idx
Once we've finished filling the dp array, we see if the tank is below 0, in which case we return -1
Otherwise, we check again starting from the beginning to idx, adding the values to our tank
If the tank falls below 0 at any point, return -1
If we're able to reach idx, we have our answer
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), tank = 0, idx = -1;
        vector<int> dp (n);
        for (int i=0; i<n; i++)
        {
            dp[i] = gas[i] - cost[i];
            tank += dp[i];
            // cout << tank << " " << dp[i] << endl;
            if (tank < 0)
            {
                tank = 0;
                idx = -1;
            }
            else if (idx == -1) idx = i;
        }
        if (tank < 0) return -1;
        for (int i=0; i<idx; i++)
        {
            tank += dp[i];
            if (tank < 0) return -1;
        }
        return idx;
    }
};