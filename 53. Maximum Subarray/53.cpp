/*
We use Kadane's algorithm for this problem
The main idea is, for every element in the array, we decide if we want to add it to the current running subarray, or start a new subarray starting from the current element
Since we don't really use the previously computed sum, we don't need a dp array
We just need 2 variables:
- currMax, storing the sum of the current running subarray
- ans, the largest sum we've encountered so far
We initialize both variables to the first element of the array, since the first element must be a subarray of the full array
Then as we go through the rest of the array, we decide whether we want to add to the currMax (extending the subarray) or set currMax to the current element (starting a new subarray) depending on which one yields the greater number
Each time, we update ans with the maximum value of currMax
Once we've finished iterating through everything, we simply return ans
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int currMax = nums[0], ans = nums[0];
        for (int i=1; i<n; i++)
        {
            currMax = max(nums[i], currMax + nums[i]);
            ans = max(ans, currMax);
            // cout << i << " " << nums[i] << " " << currMax << " " << ans << endl;
        }
        return ans;
    }
};