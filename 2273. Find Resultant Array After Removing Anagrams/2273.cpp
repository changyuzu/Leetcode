/*
For this problem, we need to check the elements of words and remove any words which is an anagram of the previous word
We can initialize the answer vector with the first element of words, since there can't be any previous element for the first element
We also declare a string called curr, which is the string we're currently checking
Then, starting from index 1, we check whether words[i] is an anagram of the current string
If yes, we skip it
Otherwise, we add words[i] to the answer vector and set it as our curr string
As for the anagram checking, I started by checking if the words are the same length
Then I sort both strings, and check whether they're the same strings
Once we've checked all elements, we simply return our ans vector
*/

class Solution {
public:
    bool isAnagram(string word, string curr)
    {
        if (word.size() != curr.size()) return false;
        sort(word.begin(), word.end());
        sort(curr.begin(), curr.end());
        return word == curr;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        string curr = words[0];
        vector<string> ans = {words[0]};
        for (int i=1; i<n; i++)
        {
            if (isAnagram(words[i], curr)) continue;
            ans.push_back(words[i]);
            curr = words[i];
        }
        return ans;
    }
};