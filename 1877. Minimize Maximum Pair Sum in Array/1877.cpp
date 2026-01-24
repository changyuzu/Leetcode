/*
This problem can be solved through sorting
Know that in order to minimize the maximum pair sum, we need to pair the LARGEST elements with the SMALLEST elements
Sorting the elements in nums allows us to pair the elements more easily
Initialize our answer to 0, or nums[0] + nums[n-1]
Once we have the elements sorted, we just need a loop for i in the range [1..n/2)
Check our answer against nums[i] + nums[n-1-i], and keep the larger one
When we've checked all pairs, return our answer
*/

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        int ans = nums[0] + nums[n-1];
        for (int i=1; i<n/2; i++)
        {
            ans = max(ans, nums[i] + nums[n-1-i]);
        }
        return ans;
    }
};