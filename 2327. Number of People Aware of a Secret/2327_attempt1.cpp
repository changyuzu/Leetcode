/*
My original idea builds on a dp with size forget
The ith element of the dp represents how many people have known the secret for i days
With each passing day, the values are shifted to the right, because if x people have known the secret for i days on day n, then on day n+1, the same x number of people will have known the secret for i+1 days
We start iterating from the rightmost element of the dp, and if the element index is larger than or equal to the delay, we add the element value to a counter for how many people can spread secrets
Then we assign the counter value to the first element of the dp, because that many people can spread secrets, meaning we have that many people who have learned the secret for the first time
Just remember to mod by 10^9 + 7 where needed
*/

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp (forget);
        dp[0] = 1;
        long long c = 0, ans = 0;
        n--;
        while (n--)
        {
            c = 0;
            for (int i=forget-1; i>0; i--)
            {
                dp[i] = dp[i-1];
                if (i >= delay) c = (c + dp[i]) % 1000000007;
                if (n==0) ans = (ans + dp[i]) % 1000000007;
            }
            dp[0] = c;
            if (n==0) ans = (ans + c);
        }
        // for (int i: dp) cout << i << " ";
        return ans % 1000000007;
    }
};