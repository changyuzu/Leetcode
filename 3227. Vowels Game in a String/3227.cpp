/*
For this problem, we just need to look at the number of vowels
Let's say the number of vowels in the string equals to x
If x == 0, Alice can't make her first move, so she loses
If x % 2 != 0, Alice can simply remove the entire string since the full string is a substring of itself with an odd number of vowels
If x % 2 == 0, Alice can remove any substring with (x-1) vowels, so the remaining substring will have 1 vowel
	Bob can't remove an odd number of vowels, so he can only remove consonants, and the remaining number of vowels stay at 1
	When Alice moves again, she can remove the entire remaining substring and win the game
So, unless there are no vowels in the string to begin with, Alice always wins
*/

class Solution {
public:
    bool isVowel(char c)
    {
        switch (c)
        {
            case 'a': case 'e': case 'i': case 'o': case 'u': return true;
            default: return false;
        }
    }
    bool doesAliceWin(string s) {
        int count = 0;
        for (char c: s) if (isVowel(c)) count++;
        return (count == 0) ? false : true;
    }
};