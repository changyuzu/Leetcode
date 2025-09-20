/*
For this problem, we can just keep track of the farthest index we can reach at each position
If the farthest index is the last index or beyond, we can simply return true
Or, if the maximum reach from the current index is still the current index, we know we can't go any further, so return false
Else, we move on to the next element in nums
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        int maxReach = 0;
        for (int i=0; i<n; i++)
        {
            // cout << i << " " << nums[i] << endl;
            maxReach = max(maxReach, i+nums[i]);
            if (i == maxReach) return false;
            else if (maxReach >= n-1) return true;
        }
        return true;
    }
};