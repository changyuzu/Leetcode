/*
This problem is quite tricky to solve within the given constraint (constant space, O(n) time)
But someone gave a great explanation in the Discussion tab, which gave me the direction for this solution
Basically, for an array of size n, if we want to find the missing value, it's either in the range [1..n] or outside the range
If the answer is outside the range, we can simply return n+1, since we only care about the SMALLEST positive integer
So how do we find if the answer is within the range? We need to prepare our array first
From what we see above, we know that the smallest positive integer can't possibly be larger than n+1
So we iterate through all elements of nums, and if we find any value outside the range [1..n], replace it with n+1
Then for the next iteration, we do the following:
- Check if the current element is within the range [1..n], if not, simply continue
- If yes, we mark the element at index [nums[i]] as visited
	- We can do this by marking the element nums[nums[i]] as a negative value
	- To avoid canceling out this mark, simply check that nums[nums[i]] is greater than 0
Once we've marked all the valid elements, do one last for-loop to find the index of the first non-negative value, which would show that this element didn't appear in our array
If there are no non-negative values, that means all elements are in the range [1..n], so return n+1
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int &num: nums) if (num < 1 || num > n) num = n+1;
        for (int &num: nums)
        {
            int idx = abs(num) - 1;
            if (idx >= n) continue;
            if (nums[idx] > 0) nums[idx] *= -1;
        }
        for (int i=0; i<n; i++) if (nums[i] > 0) return i+1;
        return n+1;
    }
};