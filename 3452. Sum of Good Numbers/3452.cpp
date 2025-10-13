/*
Start this problem with ans = 0
Then, for each element in nums, check whether the indices i-k and i+k are within bounds
If yes, check whether they're larger than or equal to nums[i]
If yes, skip this element
Otherwise, add to our ans
When done, return ans
*/

class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for (int i=0; i<n; i++)
        {
            if ((i-k >= 0 && nums[i-k] >= nums[i]) || (i+k < n && nums[i+k] >= nums[i])) continue;
            ans += nums[i];
        }
        return ans;
    }
};