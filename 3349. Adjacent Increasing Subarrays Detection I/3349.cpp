/*
One approach we can use for this problem is keeping track of the length of strictly increasing arrays as we go, for the current subarray and the previous subarray
So we need 1 pointer to keep track of the index where we last saw non-increasing values, which I named `last` in the code
We also need a variable to keep track of the length of the previous strictly increasing subarray, which I named `prev` in the code
Start our for loop from index 1 instead 0:
- If nums[i] > nums[i-1], the subarray is strictly increasing, so we just continue
- Otherwise, we check the length of the current strictly increasing subarray:
	curr = i - last
- Set last to i, because i is the index of where we last saw a non-increasing value
- If the length of the current subarray is at least 2 * k, the current subarray can hold two adjacent strictly increasing subarray, so return true
- Or, if both prev and curr both have length of at least k, both subarrays fulfill our conditions, so we also return true
- Otherwise, we set curr as our new prev
Keep in mind that the last strictly increasing subarray might be the very last elements of the array
So, if after exiting the for loop, we still haven't found our answer, try doing the check again using curr = n - last
If we still don't have our answer, return false
*/

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        if (k == 1) return true;
        int last = 0, prev = 0, n = nums.size(), curr;
        for (int i=1; i<n; i++)
        {
            if (nums[i] > nums[i-1]) continue;
            curr = i - last;
            last = i;
            // cout << prev << " " << curr << endl;
            if (curr >= 2*k || (prev >= k && curr >= k)) return true;
            prev = curr;
        }
        curr = n - last;
        // cout << prev << " " << curr << endl;
        if (curr >= 2*k || (prev >= k && curr >= k)) return true;
        return false;
    }
};