/*
This problem can be solved by using two pointers
The array elements are sorted in non-decreasing order, but since the elements could be negative, it's possible that the leftmost element is the largest element
So, we use two pointers, initialized at the two ends of the vector
Then, we start filling our ans vector of the same size as nums, starting from the end (which is supposed to be largest)
- Check if the square of the element at the left index is larger than the square of the one on the right index
	- If yes, we put nums[l] * nums[l] as ans[i], and move l one step forward
	- If no, we put nums[r] * nums[r] as ans[i], and move r one step backward
- Move index i backward
Once we've gone through all elements, return our answer vector
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans (n);
        int l = 0, r = n-1, i = r;
        while (l <= r)
        {
            if (nums[l] * nums[l] > nums[r] * nums[r])
            {
                ans[i] = nums[l] * nums[l];
                l++;
            }
            else
            {
                ans[i] = nums[r] * nums[r];
                r--;
            }
            i--;
        }
        return ans;
    }
};