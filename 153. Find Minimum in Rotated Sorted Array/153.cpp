/*
This problem can be solved using binary search
We can first check if the vector is rotated at all, by checking if the first element is smaller than the last element
Since the original array is sorted, rotating it however many times will make the first element larger than the last element
So, if the first element is smaller than the last, then the array isn't rotated and the smallest element will be the first element, and we return it directly
Otherwise, we start our binary search
With m = l + (r-l) / 2 as the middle element, we know that if nums[m] < nums[r], the elements between index m and r are sorted, and there won't be a smaller element here
Is there any chance that a smaller element exists to the right of m? Yes, but the current middle element may already be the smallest
So, when we move the right pointer, we set it as r = m instead of r = m-1, since r is still a possibility
What if nums[m] >= nums[r]? Then the elements between index m and r aren't sorted, and there might be a smaller here
So we move l inwards, and since nums[l] is larger than nums[m], it definitely can't be our answer, so we set l = m+1
We continue this while l <= r, and when we break this condition, we return nums[r]
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if (nums[0] < nums[r]) return nums[0];
        while (l <= r)
        {
            int m = l + (r-l) / 2;
            if (nums[m] < nums[r]) r = m;
            else l = m+1;
        }
        return nums[r];
    }
};