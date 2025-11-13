/*
This problem can be solved by simply keeping track of the number of ones which had at least a zero between it and the end of the string
Basically, my intuition goes like this:
- Count the number of consecutive ones (that's the number of operations to shift these ones)
- If we encounter a 0 between the ones and the end of the string, that means these ones need to be shifted, so add the number of consecutive ones to the total of ones we've seen thus far, and add the new total to our answer
- Note that we only need to add to our answer if we encounter a 0 when we have at least 1 consecutive ones
Thus, I need 3 variables, all initialized to 0:
- prev: keeps track of the TOTAL number of ones seen so far
- ans: keeps track of the TOTAL number of operations
- curr: keeps track of the CURRENT number of consecutive ones
So, for each char ch in s:
- If ch is '1', add to the number of consecutive ones
- Otherwise, if the number of consecutive ones is more than 0:
	- Add the current number of consecutive ones to the TOTAL number of ones
	- Add the new TOTAL number of ones to our answer
	- Reassign the current number of consecutive ones to 0, to signal that there's been a 0 here
Once we've checked the entire string, return the answer
*/

class Solution {
public:
    int maxOperations(string s) {
        int prev = 0, curr = 0, ans = 0;
        for (char &ch: s)
        {
            if (ch == '1') curr++;
            else if (curr > 0)
            {
                prev += curr;
                ans += prev;
                curr = 0;
            }
        }
        return ans;
    }
};