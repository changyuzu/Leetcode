/*
My first intuition for this problem was storing the values of nums in an unordered_set, and multiplying original by 2 while we can still find it in the set
But this was quite slow, as the runtime was 3ms at best
So I looked at some hints other people posted and got another solution, which uses a bitset of fixed size 10
I chose 10, because that's the minimum size to contain the largest power of 2 in the given constraints (1 <= nums[i], original <= 1000)
The intuition goes like this:
- For each element num in nums:
	- Check if num is a product of original (num % original == 0)
		- If not, continue as we don't need to check this
		- If yes, see if num / original is a power of 2 (e.g. num = 6, original = 3, as opposed to num = 9, original = 3)
			- If not, continue (num = 9, original = 3)
			- If yes, find WHICH power of 2 it is and mark this power of 2 as seen in the bitset
				- For example, num = 6, original = 3:
					6 is 2 * 3, so we can obtain 6 by multiplying 3 with 2 to the power of 1
- Once we've checked all elements in nums, we start check all the elements of the bitset b
- Starting from index i = 0 in the bitset
	- If b[i] == 0, that means we didn't see this power of 2 in nums, so we've found the power of 2 that can't be found nums, and break out of the loop
	- Otherwise, we multiple original by 2
Once we've found the first power of 2 that can't be found in nums, we return original's new value
*/

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bitset<10> b;
        for (int &num: nums)
        {
            if (num % original != 0) continue;
            num /= original;
            if ((num & (num - 1)) != 0) continue;
            int pow = 0;
            while (num > 1)
            {
                pow++;
                num >>= 1;
            }
            b[pow] = 1;
        }
        for (int i=0; i<10; i++)
        {
            if (b[i] == 0) break;
            original <<= 1;
        }
        return original;
    }
};

// class Solution {
// public:
//     int findFinalValue(vector<int>& nums, int original) {
//         unordered_set<int> s(nums.begin(), nums.end());
//         while (s.find(original) != s.end()) original <<= 1;
//         return original;
//     }
// };