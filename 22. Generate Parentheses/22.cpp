/*
This problem can be solved using backtracking
Basically, we just need to keep adding a parenthesis when we still don't have enough open and close parentheses to make up n pairs
To do this, I declared a helper function called genParen
We need to keep track of how many open and close parentheses we have in each iteration
If the number of open and close parentheses are both equal to n, we push the current string to our answer vector and return
Otherwise, we keep going
How do we decide which parenthesis to add?
For the open parentheses, we can just add them any time, as long as the number of open parentheses is less than n
Next, remember that the parentheses need to be well-formed, e.g. the close parentheses must have their own matching open parentheses
So in order to add the close parentheses, the number of close parentheses needs to be less than the number of open parentheses
With those 2 conditions in place, we have our helper function ready
Just call the genParen function in the main body and return the answer vector
*/

class Solution {
public:
    void genParen(int &n, vector<string> &ans, string &row, int open, int close)
    {
        if (open == n && close == n)
        {
            ans.push_back(row);
            return;
        }
        if (open < n)
        {
            row.push_back('(');
            genParen(n, ans, row, open + 1, close);
            row.pop_back();
        }
        if (close < open)
        {
            row.push_back(')');
            genParen(n, ans, row, open, close + 1);
            row.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string row;
        genParen(n, ans, row, 0, 0);
        return ans;
    }
};