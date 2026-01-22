/*
This problem is the same as 3314. Construct the Minimum Bitwise Array I, but with stricter constraints, so brute force won't cut it
So we'll need to look at the numbers in binary
Notice that for target number ans[i], we want to OR it with ans[i] + 1
With bitwise OR, only one number needs to have a set bit for that bit to be set in the resulting number
So we can actually just look at the last 1's before a 0
Since we want the result of (ans[i] OR ans[i] + 1) to be the number in nums, we can know that the last bit is guaranteed to be set
In other words, the number we evaluate must not be divisible by 2
So we put this condition as the very first thing to check
Then, we check the number itself
Notice that for binary numbers with a certain number of 1's at the end (let's say there are `n` ones), adding it with 1 will unset all `n` of the trailing 1's, and turn the last 0 into a 1
So, we would get a 1 followed by `n` zeroes
And, when we OR the original number with what we got from adding 1, we get `n+1` ones
With that in mind, we can get the number for ans[i]
Simply check how many 1's are at the end of a number in binary, and turn the first 1 into a 0
	For the case of nums[i] = 7 	-> 0111
	The answer becomes ans[i] = 3	-> 0011
	Check that ans[i] + 1 = 4		-> 0100
	3 OR 4	-> 0011 OR 0100 -> 0111
	This still holds true even if there are other 1's further on the left, because we want to minimize the value of ans[i]
I'm implementing my logic with a while loop
Declare an integer variable to track the number of shifts, then while (n & 1) == 1:
- Shift the bits 1 position to the right
- Increment the position
Then, once we encounter a 0 (which can also happen if nums[i] becomes 0), we do the following:
- Turn the last 1 into a 0, by simply shifting the bits 1 position to the left
- Decrement the position
- Then, turn all the remaining 1's back
	- Use a while loop that stops once the position returns to 0
		- Shift the bits 1 position to the left and OR the number with 1 to set the last bit
		- Decrement the position
To save space, I actually just modified nums in-place
Once we've gone through all the elements, simply return nums again
*/

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (auto &n: nums)
        {
            if ((n & 1) == 0)
            {
                n = -1;
                continue;
            }
            int pos = 0;
            while ((n & 1) == 1)
            {
                n >>= 1;
                pos++;
            }
            n <<= 1;
            pos--;
            while (pos > 0)
            {
                n <<= 1;
                n |= 1;
                pos--;
            }
        }
        return nums;
    }
};