/*
This problem can be solved using sliding window and hash table
So, we're going to keep a sliding window with the same size as the length of string p, and compare the elements in it against p
Since the string can only be lowercase characters, we just need to use two arrays of size 26 as our hash table
Start by building the hash table for string p, keeping track of the frequency of each character
Then we start with the sliding window, adding the frequency of the character on the right pointer, and subtracking the frequency of the character of the left pointer
If, at any point where the size of the sliding window is the same as string p, the hash table for p and s end up being the same, we add the left index to our answer vector
Once we've checked all elements, return the answer vector
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int n = p.size(), m = s.size();
        if (n > m) return {};
        vector<int> sm (26, 0), pm (26, 0);
        for (char &ch: p) pm[ch - 'a']++;
        int l = 0;
        vector<int> ans;
        for (int i=0; i<s.size(); i++)
        {
            sm[s[i] - 'a']++;
            if (i - l < n-1) continue;
            else if (i - l > n-1)
            {
                sm[s[l] - 'a']--;
                l++;
            }
            if (sm == pm) ans.push_back(l);
        }
        return ans;
    }
};