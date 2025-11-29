/*
This problem can be solved using the concept of prefix sum
For our calculation, we need 2 vectors: one to store the prefix products, one to store the suffix products
In order to save space, I used the input vector AND the output (answer) vector to store those 2 data
The nums vector will store the prefix product, and ans vector (initialized to be the same as nums) will store the suffix product
Let's visualize this using nums = [1,2,3,4]
We first start by filling up the prefix and suffix products
So, for index i = 1 to n-1, we do the following:
- ans[i] *= ans[i-1]
- nums[n-i-1] *= nums[n-1]
Thus, we get these 2 vectors:
	ans = [1,2,6,24]
	nums = [24,24,12,4]
To get the correct answer for each index i, we just need the product of the prefix (ans[i-1]) and suffix (nums[i+1])
Notice that when we iterate from the left to right, we will overwrite the value in ans[i], but we need the original value of ans[i] as the prefix of the next index
So, I stored the value of the prefix in a variable called pref, initialized to 1 (because index 0 has no prefix)
Then, for each iteration, we cast the original value of ans[i] into a temporary variable
Remember that for index n-1, the suffix will be 1, otherwise the suffix is nums[i+1]
Set ans[i] = pref * suff, then set pref as the value of the temporary variable earlier
Once we've checked all indexes, return ans
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans = nums;
        const int n = nums.size();
        for (int i=1; i<n; i++)
        {
            ans[i] *= ans[i-1];
            nums[n-i-1] *= nums[n-i];
        }
        int pref = 1;
        for (int i=0; i<n; i++)
        {
            int tmp = ans[i], suff = (i+1 < n) ? nums[i+1] : 1;
            ans[i] = pref * suff;
            pref = tmp;
        }
        return ans;
    }
};