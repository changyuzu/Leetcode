/*
This problem can be solved with dynamic programming, but we really just need the last 2 computed values for this
Basically, for each house, we need to decide if we rob it or skip it in favor of the previous house, since you can't rob adjacent houses
You could use a dp vector to keep track of the max amount of money when you reach a house, but I decided to just use 2 tracker variables:
- prev2 keeps track of the max sum at index i-2
- prev1 keeps track of the max sum at index i-1
We initialize prev2 with nums[0], and prev2 with the max value between nums[0] and nums[1] because we might skip nums[1] in favor of nums[0]
Then starting from index 2, we do the following
- If we choose to rob nums[i], the max profit from doing this would be adding prev2 to the money in nums[i]
- But do we rob nums[i]? We need to check if it's more profitable than skipping it, so we check if it's higher than prev1
- Since this value is going to be the new prev1, we simply update prev1 accordingly
- The new value of prev2 would be the original value of prev1
After we've finished checking all the values, return whichever is greater between prev1 and prev2
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int prev2 = nums[0], prev1 = max(nums[0], nums[1]);
        for (int i=2; i<n; i++)
        {
            int tmp = prev1;
            prev1 = max(prev1, prev2 + nums[i]);
            prev2 = tmp;
        }
        return max(prev1, prev2);
    }
};
