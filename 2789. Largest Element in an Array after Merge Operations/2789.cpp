/*
For this problem, we don't actually need to modify the vector
We only need to keep track of the values at the merge, and the max value seen so far
So, we can start iterating from the back (since the merge can only happen when nums[i+1] > nums[i])
If we iterate from the front, it's easy for us to lose track of the operations we could use
While merging the values in front, nums[i+1] might end up being smaller, but it could also be larger again after merging with nums[i+2]
To avoid having to compute this twice, we just start iterating from the back
Whenever we encounter elements larger than the current sum, we reset the current sum to the current element
Otherwise, we add the current element to the current sum
As we go, we update our answer with the max value between the original ans value and the new current sum
Once we've  finished checking all elements, just return ans
*/

class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long curr = nums[n-1], ans = curr;
        for (int i=n-2; i>=0; i--)
        {
            if (nums[i] > curr) curr = nums[i];
            else curr += nums[i];
            ans = max(curr, ans);
        }
        return ans;
    }
};