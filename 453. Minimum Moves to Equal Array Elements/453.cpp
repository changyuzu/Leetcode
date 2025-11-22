/*
To solve this problem, we don't actually need to care about the definition of the "move" in the problem statement, which just makes things confusing
We just need to care about getting the number of increment / decrement operations to make all array elements equal
There are two ways to go about this:
- Turn all elements into the maximum element of the array
- Turn all elements into the minimum element of the array
My solution goes with the latter, and only requires 1 pass over the vector
First, initialize the minimum element (named `least` in the code) to nums[0], and our answer to 0
Then, starting from index i = 1, we do the following
- Check if nums[i] is smaller than least
	- If yes, all the previous elements before the current one needs to get reduced to the new least element
	- Since the previous elements originally were targeted to be reduced to the previous least, all of them need to be reduced to nums[i]
	- All those previous elements would require (least - nums[i]) decrement operations to get to nums[i]
	- So, we add ((least - nums[i]) * i) to our answer, then update least with nums[i]
- Otherwise, we add the difference between nums[i] and least to our answer
Once we've checked all elements, return ans
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0, least = nums[0], n = nums.size();
        for (int i=1; i<n; i++)
        {
            if (nums[i] < least)
            {
                ans += (least - nums[i]) * i;
                least = nums[i];
            }
            else ans += nums[i] - least;
        }
        return ans;
    }
};