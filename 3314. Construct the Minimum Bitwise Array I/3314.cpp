/*
This problem can be solved with brute force, since the constraints are quite lax
To save memory, I modified nums in-place
So for each number num in nums, we just do the following:
- For i in the range [1..n-1], check if (i | (i+1)) equals n
	- If yes, turn num into i, and mark that the number has been changed
		- I used a boolean variable to mark a number's change
- If we exit the for loop without ever modifying the value for num, turn it into -1 instead
Once we've gone through all the elements, return nums
*/

class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for (auto &n: nums)
        {
            bool changed = false;
            for (int i=1; i<n; i++)
            {
                if ((i | (i+1)) != n) continue;
                n = i;
                changed = true;
                break;
            }
            if (!changed) n = -1;
        }
        return nums;
    }
};