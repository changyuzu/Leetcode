/*
This problem is actually quite easy
We just need to sort the array, and start checking from the largest element
Remember that in order to form a valid triangle, the sum of 2 of its sides need to be larger than its longest side
Since we want the largest perimeter, we can start our check from the last element
If the sum of its 2 preceeding elements are larger than the last element, then the last element fulfills our condition
In a sorted array, any elements that come before the last element can't be larger, so we can stop the iteration as soon as we find our answer
Otherwise, we continue checking the elements in front
If we've checked all the elements and still can't find any answer, return 0
*/

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i=nums.size()-1; i>1; i--)
        {
            if (nums[i] < nums[i-1] + nums[i-2])
            {
                return nums[i] + nums[i-1] + nums[i-2];
            }
        }
        return 0;
    }
};