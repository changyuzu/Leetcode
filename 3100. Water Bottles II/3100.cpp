/*
This problem is similar to 1518. Water Bottles
Except, numExchange (the no. of empty bottles required to exchange for full bottles) increments with each full bottle exchanged
Since this would require repeatedly doing the same operation, I thought a recursive approach would work well

I defined a recursive function called exchange, which returns an integer and takes 2 integers: the no. of empty bottles, and numExchange
For each function call, we see if the no. of empty bottles have gone below numExchange, in which case we return 0 since we can't exchange anymore bottles
Otherwise, we exchange numExchange empty bottles, so no. of empty bottles goes down by numExchange
Then we increment numExchange
From this operation, we just exchanged 1 full bottle, and there could still be some empty bottles left, which we can still exchange
So we can picture the no. of exchanged bottles as 1 + (the result of exchanging the remaining empty bottles)
Therefore, we call the recursive function again while also keeping track of the no. of exchanged bottles
That's why the recursive function calls itself again with return 1 + exchange(empty, numEx)

The above recursive function only returns the no. of exchanged bottles for the current step, i.e. before emptying the exchanged bottles again
Since we will empty the bottles and try to exchange them again, we need to update the no. of empty bottles AND the sum of bottles that we've emptied so far
For both, we just add the no. of exchanged bottles we obtained from the exchange function
Once the no. of empty bottles is less than numExchange, we break out of the while loop and return the sum
*/

class Solution {
public:
    int exchange(int &empty, int &numEx)
    {
        if (empty < numEx) return 0;
        empty -= numEx;
        numEx++;
        return 1 + exchange(empty, numEx);
    }
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int sum = numBottles;
        while (numBottles >= numExchange)
        {
            int exchanged = exchange(numBottles, numExchange);
            sum += exchanged;
            numBottles += exchanged;
        }
        return sum;
    }
};