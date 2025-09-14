/*
For this problem, we can utilize 2 separate hash tables: one for the lowercase strings, and one for the novowel strings
I also put the members of wordlist in a set for faster search
I defined 2 functions here: 
- stolower to convert a string to its all-lowercase version
- novowels to convert a string to all-lowercase and its vowels to any other char (I chose to replace it with a dot in this code)
When we map these hash tables, note that we should return the first match, so in the case of strings with the same lowercase / novowel versions like "KiTe" and "kite", we only keep whichever one appears first in the wordlist array
So the logic becomes: if the lowercase / novowel version of a string already exists in the hash table, we don't do anything, otherwise we add a key-value pair, where value is the original string
Once we've mapped both hash tables, we can start checking the queries
First we check if the query exists in the set
If not, we check if the case-insensitive version exists
If not, we check if the vowel-replaced version exists
If not, there's no answer, and we append an empty string to our answer vector
*/

class Solution {
public:
    bool isVowel(char c)
    {
        switch (c)
        {
            case 'a': case 'e': case 'i': case 'u': case 'o':
            case 'A': case 'E': case 'I': case 'U': case 'O': return true;
            default: return false;
        }
    }
    string stolower(string s)
    {
        for (char &c: s) c = tolower(c);
        return s;
    }
    string novowels(string s)
    {
        s = stolower(s);
        for (char &c: s) if (isVowel(c)) c = '.';
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        set<string> s;
        unordered_map<string, string> lowercase;
        unordered_map<string, string> novowel;
        for (string w: wordlist)
        {
            s.insert(w);
            string tmp = novowels(w);
            if (novowel.find(tmp) == novowel.end()) novowel[tmp] = w;
            tmp = stolower(w);
            if (lowercase.find(tmp) == lowercase.end()) lowercase[tmp] = w;
        }
        for (string q: queries)
        {
            string low = stolower(q), nov = novowels(q);
            if (s.find(q) != s.end()) ans.push_back(q);
            else if (lowercase.find(low) != lowercase.end()) ans.push_back(lowercase[low]);
            else if (novowel.find(nov) != novowel.end()) ans.push_back(novowel[nov]);
            else ans.push_back("");
        }
        return ans;
    }
};