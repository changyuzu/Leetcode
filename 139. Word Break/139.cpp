/*
This problem can be solved using DP
First, to make things easier, I put all the words in wordDict into an unordered_map, with the size of each word as its key
This allows us to quickly check the dp against the size of the words
Then, we declare a dp of size n+1 with all false values, where n is the size of the string s
Each element of the dp array signifies that there is a valid substring that ends at that index
We need size n+1 to reserve space at index 0 for the point before the string starts, or an empty string
This is because we need to check our dp against the index where the last valid checked string ends, and an empty string is always a valid starting point for our check
So, we assign dp[0] as true
Then, starting from index i = 0 of the string, we do the following:
- Check the size of the strings in wordDict, which could fit between the current index i and the ending point of the last valid substring
- If yes, for each word of that size, check whether the substring of s between the ending point and the current index is the same as that word
	- Once we've found a word that fits, assign dp[i+1] as true and exit the current for loop
Once we've check all indexes between 0 and n, return dp[n]
*/

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, vector<string>> len;
        for (string &w: wordDict) len[w.size()].push_back(w);
        int n = s.size();
        vector<bool> dp (n+1, false);
        dp[0] = true;
        for (int i=0; i<n; i++)
        {
            for (auto &[size, words]: len)
            {
                if (i + 1 - size < 0 || !dp[i + 1 - size]) continue;
                for (string &word: words)
                {
                    bool same = true;
                    for (int j=0; j<size; j++)
                    {
                        if (word[j] != s[i + 1 - size + j])
                        {
                            same = false;
                            break;
                        }
                    }
                    if (same)
                    {
                        dp[i+1] = true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};