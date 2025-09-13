/*
We can apply binary search to this problem, even though the array has been rotated
The concept remains the same: if the middle element equals our target, return the index of the middle element
Otherwise, we check which side we should go next
In either case, we know that at least one side is sorted
Taking this array as an example: [4,5,6,7,8,0,1]
The middle element is 7, and the elements to the left are sorted, while the elements on the right aren't sorted
If the target element is 5, we know we should go left, because the left elements are sorted, 5 is smaller than the middle element, and larger than the leftmost element
Otherwise, we go to the right
With the same logic, we can check this array: [7,8,0,1,2,3,4]
The middle element is 1, and the elements on the right are sorted
If the target element is 3, we know we should go right, because the right elements are sorted, 3 is larger than the middle element, and smaller than the rightmost element
Otherwise, we go to the left
What if the element doesn't exist? We take the last example array for example, and say we're searching for 9
We will go to the left, so the searched array becomes [7,8,0]
The left side is sorted, and the target is larger than the middle element, so we go to the right
The searched array becomes [0]
The binary search will attempt to make l = m+1, which goes beyond the boundary of while (l <= r), so we break out of the loop and return -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            cout << m << endl;
            if (nums[m] == target) return m;
            else if (nums[m] >= nums[l])
            {
                if (nums[l] <= target && target < nums[m]) r = m-1;
                else l = m+1;
            }
            else
            {
                if (target > nums[m] && nums[r] >= target) l = m+1;
                else r = m-1;
            }
        }
        return -1;
    }
};