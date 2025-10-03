/*
This problem isn't too hard, good for getting more familiar with backtracking
Basically, we have a holder string called row, which we add to our answer vector each time it reaches the target length, i.e. the length of digits
While it's not the target length, we keep adding and removing chars from the holder string
So, just declare an unordered_map to keep track of which digit corresponds to which chars
Then perform the backtracking
Once you've got all the possible combinations, return the answer vector
*/

class Solution {
public:
    void backtrack(string &digits, unordered_map<char, vector<char>> &hash, vector<string> &ans, string row, int idx)
    {
        if (idx == digits.size())
        {
            ans.push_back(row);
            return;
        }
        for (char &c: hash[digits[idx]]) backtrack(digits, hash, ans, row+c, idx+1);
    }
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        unordered_map<char, vector<char>> hash = {
            {'2', {'a','b','c'}},
            {'3', {'d','e','f'}},
            {'4', {'g','h','i'}},
            {'5', {'j','k','l'}},
            {'6', {'m','n','o'}},
            {'7', {'p','q','r','s'}},
            {'8', {'t','u','v'}},
            {'9', {'w','x','y','z'}}
        };
        vector<string> ans;
        backtrack(digits, hash, ans, "", 0);
        return ans;
    }
};