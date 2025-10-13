/*
For this problem, just check whether the first n characters of a word matches our prefix
I defined a function called prefCheck, which takes the string w, our prefix, and the size of the prefix as n (to avoid recomputing n)
If the length of w is less than n, return false, because there's no way it has our prefix when it's shorter than the prefix
If not, we start checking the first n chars of both w and pref
If they don't match at any point, return false immediately
If all of it matches, return true
Then, in the main body of the function, just declare the n as the size of pref, and our ans as 0
For each string w in words, if prefCheck returns true, we increment ans
When we finish checking all elements, return ans
*/

class Solution {
public:
    bool prefCheck(string &w, string &p, int &n)
    {
        if (w.size() < n) return false;
        for (int i=0; i<n; i++)
        {
            if (w[i] != p[i]) return false;
        }
        return true;
    }
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.size(), ans = 0;
        for (string &w: words)
        {
            if (prefCheck(w, pref, n)) ans++;
        }
        return ans;
    }
};