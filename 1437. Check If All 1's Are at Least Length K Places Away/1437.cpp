/*
This problem can be solved by simply keeping track of the number of consecutive 0's (the distance) and whether we've seen 1 before
We need to check whether we've seen 1 before to handle testcases like [0,1,0,0,1,0,0,1], which has leading 0's
So, while nums[i] == 0, increase the counter for 0's
Otherwise, see if we've seen 1 before, and if the number of 0's is less than k, in which case we return false
If we don't return false, track that we've seen 1, and reset the counter for 0's
If we're able to reach the end of the string without returning false, return true
*/

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int zeros = 0; // count no. of consecutive 0's, distance between 1's
        bool one = false; // whether we've seen 1 before, to handle leading 0's
        for (int &n: nums)
        {
            if (n == 0) zeros++;
            else
            {
                if (one && zeros < k) return false;
                one = true;
                zeros = 0;
            }
        }
        return true;
    }
};