/*
To solve this question, just keep in mind that a number with all set bits has to be ONE LESS THAN A POWER OF 2
So to get our answer, we simply need to get the smallest power of 2 that is STRICTLY LARGER than n, then return the number with 1 deducted from it
*/

class Solution {
public:
    int smallestNumber(int n) {
        int ans = 1;
        while (ans <= n) ans <<= 1;
        return ans-1;
    }
};