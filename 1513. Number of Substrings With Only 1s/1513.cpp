/*
This problem can be solved by simply keeping track of the current number of consecutive ones, and adding it to our answer
Consider the string s = "1111"
Let's look at the number of substrings with all 1's, as we extend the substrings
"1" -> {"1"}, ans = 1
"11" -> {"1", "1", "11"}, ans = 3
"111" -> {"1", "1", "1", "11", "11", "111"}, ans = 6
"1111" -> {"1", "1", "1", "1", "11", "11", "11", "111", "111", "1111"}, ans = 10
We can also check that "11111" has 15 substrings with all 1's, and "11111" has 21
Look at the difference in the number of substrings as we increase the length of all 1 string
You should notice that each time we add 1 to the length of the string, the answer increases as much as the length of the new substring
Therefore, for our solution, we can simply count the number of consecutive 1's and add the new length to our answer each time
Remember to reset the counter for consecutive ones when we encounter any 0's, and we're good
Do keep in mind that the answer may be too large, so we need to mod our counter and answer with 10^9 + 7 every step of the way
*/

class Solution {
public:
    int numSub(string s) {
        int MOD = 1e9 + 7, ans = 0, ones = 0;
        for (char &ch: s)
        {
            if (ch == '1')
            {
                ones = ((ones % MOD) + 1) % MOD;
                ans = ((ans % MOD) + (ones % MOD)) % MOD;
            }
            else ones = 0;
        }
        return ans;
    }
};