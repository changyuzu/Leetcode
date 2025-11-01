/*
To solve this problem using constant auxiliary space, we can modify the nums vector in-place to mark values we've seen
Remember that all integers in nums are in the range [1,n], where n is the size of nums
So we know that for any index i, nums[i-1] must also be an existing index in nums
Only values above 1 are possible in the original vector, so we can mark the value at index nums[i-1] (nums[nums[i-1]]) as its own negative value
So whenever we see that nums[nums[i-1]] is a negative value, we know that this value has been seen at a previous index in the array, so we add i to our answer
Remember that marking nums[nums[i-1]] as its own negative value means we need to check for its absolute value when getting nums[i-1]
Once we've checked all possible values, simply return ans
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int &num: nums)
        {
            int idx = abs(num) - 1;
            if (nums[idx] < 0) ans.push_back(idx+1);
            nums[idx] *= -1;
        }
        return ans;
    }
};