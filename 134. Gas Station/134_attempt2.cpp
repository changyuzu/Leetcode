/*
My second attempt removes the dp, instead keeping track of the total difference between the gas and the cost
We need 2 variables:
- total: the total of difference between gas and cost across all gas stations
- curr: the difference between gas and cost up to the current gas station
The initial value for our answer is 0
Any time curr goes below 0, we set idx to the next index and reset curr to 0
Once we've checked all the gas stations, we check total to see if it's larger than or equal 0
If yes, we return the index, which should be the index where curr has been larger than 0 all the way to the end
Otherwise, the cost of traveling the circuit is higher than the total gas, so there's no way to complete the circuit and we return -1
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), idx = 0, total = 0, curr = 0;
        for (int i=0; i<n; i++)
        {
            total += gas[i] - cost[i];
            curr += gas[i] - cost[i];
            if (curr < 0)
            {
                idx = i+1;
                curr = 0;
            }
        }
        return (total >= 0) ? idx : -1;
    }
};