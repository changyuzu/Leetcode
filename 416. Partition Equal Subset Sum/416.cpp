/*
For this problem, we need to keep track of whether we can make up the target sum with the available elements of nums
Start by getting the sum of all elements in nums
If the sum is an odd number, there's no way to create subsets with equal sums, so return false
Otherwise, the target sum is half of the total sum
How do we check if we can get the sum with our existing elements?
We can create a bool dp array of size sum+1, where each index represents whether we can get that sum from the current element
We can always get a 0 by not adding any number, so dp[0] is true
Then, for each element num of nums, we do the following:
- Start checking from the target sum, and move towards 0
- If for any index, dp[i] is true, and i+num is smaller than or equal to sum, then dp[i+num] is true
	For example, if for a certain iteration, we have num = 3, dp = [true, true, false, false, false]
	dp[1] = true, and 1+3 <= 5, so dp[4] is also true
	dp[0] = true, and 0+3 <= 5, so dp[3] is also true
	Meaning, we can add 3 to the previous subset that creates a 1, and the subset that creates a 0
Why start from the back? It's to avoid using the same element more than ones, because there might be duplicates in the nums vector
If, at any point, dp[sum] becomes true, simply return true
Once we've checked all elements in nums, return dp[sum]
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int &n: nums) sum += n;
        if (sum % 2 != 0) return false;
        sum /= 2;
        vector<bool> dp (sum+1, false);
        dp[0] = true;
        for (int &num: nums)
        {
            for (int i=sum; i>=0; i--)
            {
                if (dp[i] && i+num <= sum) dp[i+num] = true;
                if (dp[sum]) return true;
            }
        }
        return dp[sum];
    }
};