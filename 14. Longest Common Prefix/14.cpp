/*
This problem can be solved by simply comparing the chars at the set index in each string
Since the common prefix has to be the same for all strings, we can simply compare strs[0] with strs[1..n]
I assigned maxLen as 200, in accordance to the constraints
Then, for each string, we do the following comparison:
- While the string index is less than maxLen AND strs[i].size() AND strs[0].size(), if strs[0][idx] == strs[i][idx]m move idx forward
- Redefine maxLen as the minimum of maxLen and the last index where the prefix are the same
- If maxLen == 0, return an empty string
Lastly, return the substring of strs[0] from index 0 to maxLen
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int maxLen = 200;
        for (int i=1; i<strs.size(); i++)
        {
            int len = 0;
            while (len < maxLen && len < strs[i].size() && len < strs[0].size())
            {
                if (strs[0][len] != strs[i][len]) break;
                len++;
            }
            maxLen = min(maxLen, len);
            if (maxLen == 0) return "";
        }
        return strs[0].substr(0, maxLen);
    }
};