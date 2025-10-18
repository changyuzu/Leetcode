/*
For this problem, I keep track of the target values for each element, check if it's within range, and update the target values accordingly
What are the target values? We start from the lowest possible value, then check the next target with each element
Since we're checking from the lowest possible value, sorting the vector would be useful
We initialize the target as INT_MIN and ans as 0
For each index i in nums, we do the following:
- If target is below or equal to nums[i] + k, we can get our target value using the current nums[i], so we increment our answer counter
	- Update the target value with whichever is higher, target + 1 or nums[i] - k + 1
What's the logic behind this method? Consider the following vector:
	nums = 		[4,4,4,4,5,9,9,9], k = 1
Applying the logic above would get us the following target values, arranged with the same index as their respective index in nums
The answer vector tracks whether they meet our requirements of the target being within nums[i] + k
 target = [INT_MIN,4,5,6,6,7,9,10]
	answer = 	[T,T,T,F,T,T,T,T]
We can see that at i = 3, the target value becomes 6, which we can't obtain using 4 + 1, so we don't add to our ans and keep the target as is
Then we reach i = 4, and we can meet the target of 6 using 5 + 1, so we add to our ans and update our target to 7
Now we reach i = 5, and the target is still within the range of nums[i] - k (9 - 1)
But since our newer value is higher than our target, we need to update our target accordingly, and target becomes nums[i] - k + 1
Once we've checked all elements, we simply return our ans
*/

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size(), target = INT_MIN;
        for (int &num: nums)
        {
            if (target <= num + k)
            {
                ans++;
                target = max(target + 1, num - k + 1);
            }
        }
        return ans;
    }
};