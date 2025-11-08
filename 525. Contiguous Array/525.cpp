/*
This problem can be solved with something like a prefix sum
Basically, for each element nums, we increment the sum if nums[i] is 1, and decrement if nums[i] is 0
With this logic, we know that when the sum becomes 0, there must be an equal number of 1's and 0's
Take [0,1,0,0,1,0,1,1] for example, and list out how sum changes with each index
	 [-1,0,-1,-2,-1,-2,-1,0]
From the example above, however, we can also observe that there are other contiguous subarrays with an equal number of 0's and 1's
	Index [1..2] -> [1,0]
	Index [1..6] -> [1,0,0,1,0,1]
	Index [2..7] -> [0,0,1,0,1,1]
	and so on
What do these subarrays have in common? If we look at the sum for each index, we'll notice that the subarrays have an equal number of 1's and 0's when the sum at the index before the starting index is the same as the sum at the ending index
Therefore, we need to keep track of the index where we first saw a sum value
Then, when we see that value again as we go through the next elements, we check if the length of the current index - first seen index is longer than the longest subarray seen thus far
Once we've checked all the elements, return the length of the longest subarray we've seen
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, maxLen = 0;
        unordered_map<int, int> idx;
        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i] == 1) sum++;
            else sum--;
            if (sum == 0) maxLen = max(maxLen, i+1);
            else if (idx.find(sum) == idx.end()) idx[sum] = i;
            else maxLen = max(maxLen, i - idx[sum]);
        }
        return maxLen;
    }
};