/*
This problem can be solved by applying binary search twice
The first one searches for the index of the last element that is smaller than 0, i.e. the number of negative elements
The second one searches for the index of the last element that is smaller than 1, which we can use to deduce the number of positive elements
	- Once we have the last index that's smaller than 1, all elements after it will be at least 1, i.e. positive numbers
		- Let's call this index idx
	- So the number of positive numbers will be nums.size - idx
Once we have both the number of positive elements and negative elements, just return the max between the two
*/

class Solution {
public:
    int binarySearch(vector<int> &nums, int target, const int &n)
    {
        int l = 0, r = n-1, ans = -1;
        while (l <= r)
        {
            int m = l + (r-l) / 2;
            if (nums[m] < target)
            {
                ans = m+1;
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
    int maximumCount(vector<int>& nums) {
        const int n = nums.size();
        if (nums[0] > 0 || nums[n-1] < 0) return n;
        int numNeg = binarySearch(nums, 0, n), numPos = n - binarySearch(nums, 1, n);
        // cout << numNeg << " " << numPos << endl;
        return max(numNeg, numPos);
    }
};