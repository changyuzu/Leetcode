/*
My first idea is practically brute-forcing it
We know that the next iterations will have less length and will reuse elements from the previous iteration
So I modified the nums vector in-place, which means we don't need additional space
For each index i, the new value for nums[i] is (nums[i] + nums[i+1]) % 10
Since we only look ahead for each index, modifying index i in-place won't change the next elements
Then, we only need to return the first element, because the size of the vector will keep shrinking until n == 1
*/

class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        while (n--)
        {
            for (int i=0; i<n; i++)
            {
                nums[i] = (nums[i] + nums[i+1]) % 10;
            }
        }
        return nums[0];
    }
};