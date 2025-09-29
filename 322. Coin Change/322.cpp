/*
This problem can be solved using dp
If the target amount is 0, we can simply return 0, since we don't need to do anything to get a total of 0
Otherwise, we create a dp vector of size amount+1 to store the number of coins to make up amount
We also initialize each index as amount+1, so when we check for the min values, we won't get any unexpected errors
I didn't use INT_MAX for the initial values, because INT_MAX+1 will result in signed integer overflow
Then we start checking each coin
If the coin is larger than our target amount, we can't use it, so we skip it
Otherwise, we know that the minimum number of coins we need to make the value of the coin is 1, so we set dp[c] = 1
Then we start iterating from the element after the coin, and see whether the previous value of dp[i] is less than dp[i-c] + 1
Why? Take coins {1,2} for example, and the target amount is 3
Initially, the dp is like this: dp = {4,4,4,4}
When we check coin = 1:
	dp[1] = 1									dp = {4,1,4,4}
		dp[2] = min(4, dp[1] + 1) = dp[1] + 1	dp = {4,1,2,4}	Because we can create 2 using two 1 coins
		dp[3] = min(4, dp[2] + 1) = dp[2] + 1	dp = {4,1,2,3}	Because we can create 2 using three 1 coins
Then we check coin = 2:
	dp[2] = 1									dp = {4,1,1,3}	Because we know we can get amount 2 using only 1 coin now
		dp[3] = min(3, dp[1] + 1) = dp[1] + 1	dp = {4,1,1,2}	Because we can now use one 1 coin AND one 2 coin
Do note that if coins had only been {2}, dp[3] would've been min(4, dp[1] + 1) = min(4,5) = 4, since we couldn't form 1 with any of the coins
Hence, after we've finished checking all the coins, we simply check the last element, which is dp[amount]
If dp[amount] is still amount+1, there's no way to form that amount, and we return -1
Otherwise, we return dp[amount]
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> dp(amount+1, amount+1);
        for (int &c: coins)
        {
            if (c > amount) continue;
            dp[c] = 1;
            for (int i=c+1; i<=amount; i++) dp[i] = min(dp[i], dp[i-c] + 1);
        }
        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};