/*
For this problem, we can use 2 pointers after fixing 1 number
But in order to implement this more easily, the array needs to be sorted
Sorting the array allows us to skip duplicates and easily figure out when we no longer need to iterate through the array
After we've fixed one of the numbers to index i, we use pointers l = i+1 and r = n-1
We set a target to the negative value of nums[i], and check if nums[l] + nums[r] == target
Since the array is sorted, if the sum is larger, we simply move r to the left
With the same logic, if the sum is smaller, we move l to the right
When we find that the sum is equal to our target, we append the numbers at i, l, and r to our answer array, then move l and r inwards
Note that we need to skip through duplicate values for all 3 of our pointers
When nums[i] is larger than 0, we can simply break out of the loop
We need negative values to make 0 out of positive values, but with a sorted array, elements on the right of a positive value will never be a negative value
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        int i = 0;
        while (i < n-2)
        {
            if (nums[i] > 0) break;
            int target = - nums[i], l = i+1, r = n-1;
            while (l < r)
            {
                int tmp = nums[l] + nums[r];
                if (tmp > target) r--;
                else if (tmp < target) l++;
                else
                {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    r--;
                    while (r >= 0 && nums[r] == nums[r+1]) r--;
                    l++;
                    while (l < n && nums[l] == nums[l-1]) l++;
                }
            }
            i++;
            while (i < n && nums[i] == nums[i-1]) i++;
        }
        return ans;
    }
};