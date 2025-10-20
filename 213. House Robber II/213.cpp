/*
This problem is similar to 198. House Robber
We just need to keep in mind that we can't rob the first house and the last house at the same time
So, the workaround is keeping track of 2 separate sets of prev values:
- prev2_s for index i-2, prev1_s for index i-1
- prev2_e for index n-i+1, prev1_e for index n-1
First, check if nums only has 1 element, in which case simply return nums[0]
Otherwise, we initialize the original values, and ans to the max between prev1_s and prev1_e
Then we start checking from index [2..n-2], since we can't rob the first and the last houses at the same time
Update ans with the max of each iteration, then return once we've checked all houses
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int prev2_s = nums[0], prev1_s = max(nums[0], nums[1]),
        prev2_e = nums[n-1], prev1_e = max(nums[n-1], nums[n-2]),
        ans = max(prev1_s, prev1_e);
        for (int i=2; i<n-1; i++)
        {
            int curr_s = max(nums[i] + prev2_s, prev1_s), curr_e = max(nums[n-1-i] + prev2_e, prev1_e);
            prev2_s = prev1_s;
            prev1_s = curr_s;
            prev2_e = prev1_e;
            prev1_e = curr_e;
            ans = max(ans, max(curr_s, curr_e));
        }
        return ans;
    }
};