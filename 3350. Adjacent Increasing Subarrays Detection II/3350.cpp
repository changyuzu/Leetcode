/*
The solution to this problem is similar to 3349. Adjacent Increasing Subarrays Detection I
Except, instead of k being a set value, we need to keep track of the max value of k ourselves
The method is still the same, we need to keep track of the longest strictly increase subarrays, both for the current subarray and previous subarray
To do this, I declared a few variables:
- last: index of last non-increasing value
- prev: length of previous strictly increasing subarray
- curr: length of current strictly increasing subarray
- ans: answer
Starting from index 1, we do the following:
- If nums[i] > nums[i-1], the current subarray is still strictly increasing, so continue to the next index
- Otherwise, the current subarray is no longer strictly increasing, do the following:
	- Calculate length of current strictly increasing subarray: curr = i - last
	- Set i as last, the index of last non-increasing value
	- Update ans; there are 3 possible options, which we need to find the max value for:
		- ans itself
		- The min of curr and prev, since the length of the subarrays need to be the same
		- Half the length of curr, since it's possible that the adjacent strictly increasing subarrays are part of a longer strictly increasing subarray
Once we've finished checking, remember to check the length of the last subarray with curr = n - last
Try checking ans again before returning
*/

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size(), last = 0, prev = 0, ans = 0, curr;
        for (int i=1; i<n; i++)
        {
            if (nums[i] > nums[i-1]) continue;
            curr = i - last;
            last = i;
            ans = max(ans, max(curr / 2, min(curr, prev)));
            prev = curr;
        }
        curr = n - last;
        ans = max(ans, max(curr / 2, min(curr, prev)));
        return ans;
    }
};