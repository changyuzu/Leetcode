/*
Basically you need to keep track of how many bottles you have after exchanging
The initial sum will be the number of bottles we have at first
Then, as long as the number of bottles is larger than or equal to the number of bottles it takes to exchange with a full bottle (i.e. as long as we can still get full water bottles), we keep exchanging bottles
For each iteration, we keep track of a few things:
- No. of bottles exchanged: numBottles div numExchange
- No. of bottles not exchanged: numBottles mod numExchange
Do keep note that bottles that were not exchanged in one step can still be used in future steps, as illustrated in Example 2
We add the no. of exchanged bottles to our sum
The new no. of bottles will be the sum of exchanged bottles and the bottles not exchanged
As long as the new no. of bottles still allows for exchange, we keep the while loop going
Once the no. of bottles no longer allow exchanging, we break out of the loop and return our final sum
*/

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = numBottles;
        while (numBottles >= numExchange)
        {
            int exchanged = numBottles / numExchange;
            // cout << numBottles << " " << sum << " " << numExchange << " " << exchanged << endl;
            sum += exchanged;
            int rem = numBottles % numExchange;
            numBottles = exchanged + rem;
        }
        return sum;
    }
};