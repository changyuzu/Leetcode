/*
For this problem, we can implement a hash table using a boolean vector of size 26 for all the alphabets, to store whether the key for that alphabet is broken
The vector index will be the integer representation of that char - 'a'
We iterate through each char in brokenLetters and mark it as true in the vector
After that, we start iterating through each char in text, with a counter to keep track of the words we can type
I use a flag to keep track of whether we've encountered a broken letter so far, which is reset each time we encounter a space character, with the following conditions:
- If flag is true when we encounter the space, we add to the counter
- If flag is false, we don't add to the counter and simply reset the flag to true
Since the problem statement explicitly states that there are no leading or trailing spaces, we don't need to worry about multiple spaces in a row messing up our counter
*/

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> broken(26, false);
        for (char c: brokenLetters) broken[(int)c - 'a'] = true;
        bool flag = true;
        int c = 0;
        for (char ch: text)
        {
            if (ch == ' ')
            {
                if (flag) c++;
                else flag = true;
            }
            else if (broken[(int)ch - 'a']) flag = false;
        }
        if (flag) c++;
        return c;
    }
};