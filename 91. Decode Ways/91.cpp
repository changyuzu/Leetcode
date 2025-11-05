/*
This problem can be solved with dynamic programming
First, check whether the string has leading zeroes, in which case there is no valid way to decode it, and we simply return 0
Otherwise, we initialize the dp vector with size n+1, where n is the size of the string
dp[i+1] will represent the number of ways you can decode the string up to index i
dp[0] will represent an empty string, and dp[1] will represent index 0
Set dp[0] and dp[1] as 1, because there is bound to be 1 way to decode an empty string and a string with one char
What do we mean decode an empty string? Say we have s = "26"
We could decode it as '2', '6' or '', '26'
Basically dp[0] is a placeholder, for when the first two elements can be decoded as a valid string
I declared a variable `prev` to represent the number of the char at the previous index
Then, starting from index 1 in the string, we do the following:
- Get the current element's integer form
- If the current element isn't 0, then there has to be a way to decode it by adding s[i] to the substring up to s[i-1], so we add dp[i] to dp[i+1]
- Next, we check if the previous element is 1 or 2
	- If yes, we check if the current element is smaller than 2, or prev is 1, which would mean that the element is in the range [10, 26]
		- In this case, we can decode the string by adding s[i-1] and s[i] to the substring up to s[i-2], so we add dp[i-1] to dp[i+1]
- If, at any point, dp[i+1] becomes 0, there is no way to decode the rest of the string, so return 0
	- To prove this, take s = 306
		- dp[0] = 1	-> ""
		- dp[1] = 1	-> "3"
		- dp[2] = 0	->
			s[1] is 0, which means we can't create a substring by adding s[1] to the prior substring
			s[0] is 3, making s[0:1] 30, which isn't in the range [10,26], so we can't create a substring by adding s[0:1] to the empty string
			Since s[1] doesn't fulfill any of the conditions that makes decoding possible, dp[2] remains 0
		- dp[3] = 0 ->
			s[2] is 6, which means we can create a substring by adding s[2] to the substring up to index 1, so we try to add dp[2], but it's 0
			s[1] is 0, making s[1:2] 6, which isn't in the range [10,26], so we can't create a substring by adding s[1:2] to the substring up to index 0
			Therefore, if dp[i] ever ends up as 0 for any index i, the rest of the substring can't be decoded
- Set the current element's integer form as prev
If we're able to reach the end of the string, return dp[n]
*/

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int n = s.size(), prev = s[0] - '0';
        vector<int> dp(n+1, 0);
        dp[0] = 1; dp[1] = 1;
        for (int i=1; i<n; i++)
        {
            int curr = s[i] - '0';
            if (curr != 0) dp[i+1] += dp[i];
            if (prev < 3 && prev > 0 && (curr < 7 || prev == 1)) dp[i+1] += dp[i-1];
            // cout << prev << " " << curr << " " << dp[i+1] << endl;
            if (dp[i+1] == 0) return 0;
            prev = curr;
        }
        return dp[n];
    }
};