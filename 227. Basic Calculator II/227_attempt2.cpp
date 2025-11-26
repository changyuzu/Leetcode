/*
My second attempt doesn't use stacks, only 3 integer variables and 1 char for the operator
The integer variables are:
- ans: the current calculated answer
- curr: the current number
- prev: the previous seen number
We start with all integers initialized to 0, and the operator to '+'
Now, instead of only checking within the bounds of the string, we check from index 0 to n, where n is the size of the string
We do this because instead of evaluating the current operator, we evaluate the PREVIOUS operator instead
So when we evaluate 3 + 2 * 2, when we reach '*', we're actually evaluating the previous operator, which is '+'
Having the for loop extend to index n allows us to evaluate all operators
When we reach index n, we simply put the current char ch to any random operator (I used '+' in the code)
The concept is quite similar, other than the operator handling:
- If ch is a space, continue
- If ch is a digit, add it to the current number with formula curr = curr * 10 + (ch - '0')
- Otherwise, ch is an operator, so we check the previous operator op:
	- If op == '+', we can just add the previous number to our answer, then set our current number as the previous number
	- If op == '-', add the previous number to our answer, then set the negative value of our current number as the previous number
	- If op == '*', simply multiply the previous number with the current number
	- If op == '/', divide the previous number with the current number
	- Once we've evaluated the previous operation, set the current operator as the new operator, and reset the current number to 0
Now, we will reach the end of the string with the last number set as prev
We just need to return ans + prev, because we haven't calculated prev yet, and we're done
*/

class Solution {
public:
    int calculate(string s) {
        int ans = 0, curr = 0, prev = 0, n = s.size();
        char op = '+';
        for (int i=0; i<=n; i++)
        {
            char ch = (i == n) ? '+' : s[i];
            if (ch == ' ') continue;
            else if (isdigit(ch)) curr = curr * 10 + (ch - '0');
            else
            {
                if (op == '+')
                {
                    ans += prev;
                    prev = curr;
                }
                else if (op == '-')
                {
                    ans += prev;
                    prev = -curr;
                }
                else if (op == '*') prev *= curr;
                else if (op == '/') prev /= curr;
                op = ch;
                curr = 0;
            }
            // cout << ans << " " << prev << " " << curr << endl;
        }
        return ans + prev;
    }
};