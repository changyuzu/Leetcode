/*
Here, we check for palindromes for every position i in string s
We define palLen to check the length of the palindrome at position i
The palLen function takes 2 integers, the left and right pointers, which will continue expanding as long as l and r are within bounds, and s[l] == s[r]
In the main function, we call palLen for two conditions:
	l = i, r = i	For odd-length palindromes
	l = i, r = i+1	For even-length palindromes
Because the palindrome might have even length, like for string "cbbd", with the answer "bb"

Once we have the length of the palindrome, we can check if the length of the current palindrome is longer than our past encountered palindromes
The C++ substr function just needs the left position and length of string, so we just need to calculate the left pointer of the palindrome
We can find the left pointer from the index i and maxLen: l = i - (maxLen - 1) / 2
Why (maxLen - 1)? Take "cbabab" for example:
c b a b a b
0 1 2 3 4 5
The longest palindrome can be found at index i = 3, maxLen = 5
We can clearly see that the left pointer is l = 1 = 3 - 2 = 3 - (5-1) / 2

What about even-length palindromes? Take "cbbbbd" for example:
c b b b b d
0 1 2 3 4 5
The longest palindrome can be found at index i = 2, maxLen = 4
We can clearly see that the left pointer is l = 1 = 2 - 1 = 2 - (4-1) / 2
*/

class Solution {
public:
    int palLen(string &s, int l, int r)
    {
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return r - l - 1;
        /*
        Usually, the length of the substring between r and l is calculated as r - l + 1
        But here, we deduct 1 because the while loop keeps going until we go out of bounds or s[l] != s[r] 
        Therefore, the index that actually fulfills the condition is the previous l and r
        In other words, l+1 and r-1
        But we don't care about the actual index, so we just return (r-1) - (l+1) + 1 = r - l - 1
        */
    }
    string longestPalindrome(string s) {
        int n = s.size(), maxLen = 0, l = -1;
        for (int i=0; i<n; i++)
        {
            int len = max(palLen(s, i, i), palLen(s, i, i+1));
            if (len > maxLen)
            {
                maxLen = len;
                l = i - (maxLen - 1) / 2;
            }
        }
        return s.substr(l, maxLen);
    }
};