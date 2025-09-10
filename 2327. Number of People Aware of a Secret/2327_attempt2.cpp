/*
Second attempt builds on another dp approach, in which dp[i] represents the new people who have learned of the secret on day i
Day 1, 1 person learns the secret, so dp[1] has to be 1
We assign a counter c to keep track of how many people can spread the secret
Starting from day 2, we add to the counter when we've gone beyond the delay time, and subtract from the counter when people start forgetting
The dp only keeps track of people who newly learned of the secret on the ith day, so we can add and subtract from the dp directly
We still need to apply mod 10^9 + 7 as needed, but we need to add 10^9 + 7 whenever we update the counter c
At some points, c might go beyond 10^9 + 7, which means c gets a lower value
But c would get deducted by another value, which might make the original value go back to below 10^9 + 7
If we don't add 10^9 + 7 in our operations, we might end up with negative values in our counter, so always add 10^9 + 7
For the answer, we only count the last `forget` days where people still remember the secret
*/
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp (n+1, 0);
        dp[1] = 1;
        long long c = 0, ans = 0, MOD = 1000000007;
        for (int i=2; i<=n; i++)
        {
            if (i - delay > 0) c = (c + dp[i - delay] + MOD) % MOD; // + MOD to avoid negative values
            if (i - forget > 0) c = (c - dp[i - forget] + MOD) % MOD; // + MOD to avoid negative values
            dp[i] = c;
        }
        // for (int i: dp) cout << i << " ";
        for (int i = n - forget + 1; i <= n; i++) ans = (ans + dp[i]) % MOD;
        return ans % 1000000007;
    }
};