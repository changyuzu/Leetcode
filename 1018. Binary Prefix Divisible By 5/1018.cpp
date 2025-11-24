/*
For this problem, we just need to need the value of the new number mod 5
Notice that whenever we add another number to an existing prefix, we shift the previous value one bit to the left, then add the new number
Shifting a number to the left effectively multiplies it by 2
So the new number becomes ((num * 2) + n) or ((num << 1) + n), where num is the prefix number, and n is the new number to be added
But notice that the length of nums could reach 10^5, which could cause an integer overflow if we store the full number each time
To prevent this, we can just store the value of num % 5, since that's what we need anyway
Hence, the number we store is (((num * 2) + n) % 5) or (((num << 1) + n) % 5)
And for each updated number, we check whether num % 5 == 0 (num is divisible by 5) and push the result into our answer vector
Once we've iterated over the whole nums vector, return the answer vector
*/

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int num = 0;
        for (int &n: nums)
        {
            num = ((num << 1) + n) % 5;
            ans.push_back(num == 0);
        }
        return ans;
    }
};