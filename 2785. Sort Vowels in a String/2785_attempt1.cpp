/*
My approach iterates through the string and keeps track of the vowels as they appear in a separate vector
We define a function called isVowel to check whether a char is a vowel
If no vowels are found, return the string as is
If we find vowels, sort the vector storing the vowels, then iterate through the string again
We replace the vowels with the correct order from the sorted vowel vector
Since we replace the vowels in-place, we return the same string
*/

class Solution {
public:
    bool isVowel(char c)
    {
        switch (c)
        {
            case 'A': case 'E': case 'I': case 'O': case 'U': 
            case 'a': case 'e': case 'i': case 'o': case 'u': 
                return true;
            default: return false;
        }
    }
    string sortVowels(string s) {
        vector<char> v;
        int n = s.size();
        for (char c: s) if (isVowel(c)) v.push_back(c);
        if (v.size() == 0) return s;
        sort(v.begin(), v.end());
        int vIndex = 0;
        for (int i=0; i<n; i++) if (isVowel(s[i])) s[i] = v[vIndex++];
        return s;
    }
};