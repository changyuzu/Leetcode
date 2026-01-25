/*
This problem can be solved by sorting and utilizing the sliding window approach
Since we want to minimize the difference between the highest and lowest of the k scores, it would be best to ensure that all k scores are as close in values as possible
So, we sort the vector
Then we maintain a sliding window of size k, and compare the difference between the first and last element
Store this difference in our answer integer, comparing against the next window as we go, and storing the smallest difference we see
Once we've reached the end of the array, return our answer
*/

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0;
        sort(nums.begin(), nums.end());
        int ans = INT_MAX, l = 0;
        for (int i=0; i<nums.size(); i++)
        {
            if (i - l < k-1) continue;
            if (i - l == k) l++;
            // cout << l << " " << i << endl;
            ans = min(ans, nums[i] - nums[l]);
        }
        return ans;
    }
};