/*
This problem is similar to 53. Maximum Subarray
But, where Problem 53 finds the subarray with the largest sub, the current Problem 152 finds the subarray with the largest product
We can use a similar intuition to what we did in Problem 53, which was keeping track of the largest sum that ends at the current subarray
But here, we need to keep track of both the largest product and the smallest product
This is because the smallest number might yield higher product, for example when multiplying two negative numbers
So, we have 3 variables to keep track of:
- ans, the largest product we've seen so far, initialized to nums[0]
- currMax, the largest product ending at the current element, initialized to 1
- currMin, the smallest product ending at the current element, initialized to 1
Then, for each element num in nums, we update currMax and currMin, checking for the max and min values between (currMin * num, currMax * num, num)
Because we want to know whether we use the product of num with currMax or currMin, or don't take any of those and start a new subarray
Then, update ans with the max value between it and currMax
Once we've checked all the elements, return ans
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = nums[0], currMax = 1, currMin = 1;
        for (int &num: nums)
        {
            int tmp = currMax * num; // prevents currMin not being checked against the original currMax * num value, since we're updating currMax first
            currMax = max({currMin * num, tmp, num});
            currMin = min({currMin * num, tmp, num});
            ans = max(currMax, ans);
            // cout << tmp << " " << currMax << " " << currMin << " " << ans << endl;
        }
        return ans;
    }
};