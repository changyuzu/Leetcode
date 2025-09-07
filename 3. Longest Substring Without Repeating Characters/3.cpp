/*
For this problem, we use a hashmap to keep track of how many times we've encountered a character, and two pointers to keep track of the window
Every time we move the right pointer, we add 1 to the hashmap of the char in the position of the right pointer
If it goes above 1, we start moving the left pointer while reducing the counter for the char in the position of the left pointer
For each iteration, we keep track of the longest substring up till that point
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int n = s.size(), l = 0, maxLen = 0;
        for (int i=0; i<n; i++)
        {
            hash[s[i]]++;
            while (hash[s[i]] > 1)
            {
                hash[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, i-l+1);
        }
        return maxLen;
    }
};