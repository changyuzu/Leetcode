/*
To solve this problem easily, we need to remember 2 things:
- We only want palindromic subsequences of length 3
- Each unique palindromic subsequence is only counted ONCE
The first condition narrows down our problem greatly, since for a string of length 3 to be a palindrome, the first and last character needs to be the same
Once we've fixed the first and last character, we just need to check the characters in between them
Now that we've got the idea, we can start the implementation
In the first iteration over the string, we need to keep track of two things for each character: the first occurrence and the last occurrence
Once we've obtained each character's first and last occurrences, we check all the 26 possible alphabets
If the last occurrence of a certain alphabet is less than 2 indexes after the first one, there's no way to fit another character between them, so we simply continue
Otherwise, we need to start checking all the characters between the two indexes, and make sure to only count each unique character once
For this, I declared a bitset of size 26, which will keep track of whether we've seen this character before
If we've seen the character before, simply continue
Otherwise, mark it as seen, and add 1 to our answer
Once we've checked all the characters, return the answer
*/

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first (26, -1);
        vector<int> last (26, -1);
        int ans = 0, n = s.size();
        for (int i=0; i<n; i++)
        {
            int ch = s[i] - 'a';
            if (first[ch] == -1) first[ch] = i;
            last[ch] = i;
        }
        for (int i=0; i<26; i++)
        {
            if (last[i] - first[i] < 2) continue;
            bitset<26> b;
            for (int j=first[i]+1; j<last[i]; j++)
            {
                int ch = s[j] - 'a';
                if (b[ch] == 1) continue;
                b[ch] = 1;
                ans++;
            }
        }
        return ans;
    }
};