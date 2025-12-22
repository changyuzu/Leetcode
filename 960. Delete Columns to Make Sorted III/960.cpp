/*
This problem can be solved by keeping track of the longest increasing subsequence
Basically, we need these variables:
- DP vector the size of the length of the string, initialized to all 1 (since all indexes' single element, by itself, is an increasing subsequence)
- The answer, initialized to n-1
Then we need 3 for loops
- The first layer is for the end point of the subsequence
- The second layer is for matching elements between the start and the end point
- The third layer checks the strings
So, the logic goes like this:
- For all indexes, check all elements to check for the longest increasing subsequence that ends at that index
	- With i as the end index and j as the compared index, we check j in the range of [0..i-1] to see if all string char in column j is less than or equal to the char in column i
		- If we see that strs[k][j] > strs[k][i] for any string at index k, we mark this column as invalid in the increasing subsequence, and break out of the for loop for the strings
	- If j reaches i-1 without being marked as invalid, we update dp[i] with max(dp[i], dp[j] + 1), because there is an increasing subsequence ending at j which can be extended to i
- Each time we finish the for loop for j, we update our answer with min(ans, n - dp[i])
	- The dp keeps track of the longest increasing subsequence, but we want the MINIMUM NUMBER OF COLUMNS TO REMOVE, which is (length of string) - (length of longest increasing subsequence)
Once we've gone through all the columns, return ans
*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int m = strs.size(), n = strs[0].size();
        int ans = n-1;
        vector<int> dp(n, 1);
        for (int i=1; i<n; i++)
        {
            for (int j=0; j<i; j++)
            {
                bool valid = true;
                for (int k=0; k<m; k++)
                {
                    if (strs[k][j] > strs[k][i])
                    {
                        valid = false;
                        break;
                    }
                }
                if (valid) dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = min(ans, n - dp[i]);
        }
        return ans;
    }
};