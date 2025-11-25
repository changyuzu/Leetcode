/*
For this problem, we actually just need to keep track of the remainder of the current number when divided by k, instead of the full all 1 number
But before all that, we can save time by simply checking whether k is divisible by 2 or 5
If yes, we return -1, because an integer with only the digit 1 can't possibly be divided by 2 and 5
Otherwise, we start our check by declaring our number and the length of the all 1 integer, both initialized to 0
Then, for i in the range [1..k], we do the following:
- Update num with its new value: num = (num * 10 + 1) % k
	- We don't actually care about num's original value, just its remainder
	- Keeping the full value may cause num to become very large, and it may not fit in the int variable
	- Therefore, we only keep the remainder
- Increment len, for the length of the all 1 integer
- Check if num is 0, which would mean the current num is divisible by k, in which case we return len
If we've reached k and still can't get the remainder to be 0, return -1
*/

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 5) return -1;
        int num = 0, len = 0;
        for (int i=1; i<=k; i++)
        {
            num = (num * 10 + 1) % k;
            len++;
            if (num == 0) return len;
        }
        return -1;
    }
};