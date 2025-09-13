/*
For this problem, we just need to count the frequency of each character, determine if it's a vowel, and update the maximum frequency of vowels and consonants accordingly
We can use a fixed-size vector as our hash table to store the frequency of each character
Since the input string only consists of lowercase English characters, we just need a vector of size 26
I declared a separate function called isVowel to check whether a character is a vowel, but you can also check for vowels by their converted integer value
*/

class Solution {
public:
    bool isVowel(char c)
    {
        switch(c)
        {
            case 'a': case 'e': case 'i': case 'o': case 'u': return true;
            default: return false;
        }
    }
    int maxFreqSum(string s) {
        vector<int> count(26, 0);
        int vcount = 0, ccount = 0;
        for (char c: s)
        {
            int ch = c - 'a';
			// Note that we can also check for vowels using the value of ch here
            count[ch]++;
            if (isVowel(c)) vcount = max(vcount, count[ch]);
            else ccount = max(ccount, count[ch]);
        }
        return vcount + ccount;
    }
};