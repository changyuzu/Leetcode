/*
This problem can be solved by simply keeping track of the number of consecutive days where the price of each day is lower than the preceding day by exactly 1
For a smooth descent period of n days ending at index i, there are n valid periods ending at i which are also smooth descent periods, with length in the range of [1..n]
Consider the following example: [4,3,2,1]
Check the smooth descent period that ends at each index:
- i=0, price = 4	[4]
- i=1, price = 3	[4,3],[3]
- i=2, price = 2	[4,3,2],[3,2],[2]
- i=3, price = 1	[4,3,2,1],[3,2,1],[2,1],[1]
It's now clear that for each index, we just need to keep track of the consecutive number of days which are part of the same smooth descent period, and add it to our answer
Remember that the answer might be very large, so cast it into long long
*/

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        const int n = prices.size();
        long long ans = 1;
        int count = 1;
        for (int i=1; i<n; i++)
        {
            if (prices[i] + 1 == prices[i-1]) count++;
            else count = 1;
            ans += count;
        }
        return ans;
    }
};