/*
My first attempt builds on checking which users need to be taught a new language, and what language has the most speakers
We define a function hasCommonLang to check whether two friends share a common language
The counter maxSpeaker keeps track of which language has the most speakers, needTeach keeps track of how many people need to be taught a new language
The vector lang keeps track of the number of speakers for a certain language
The vector comm keeps track of whether a person needs to learn a new language
For each friendship, we first check if they have a common language
If not, check if comm[u] is true, if not, increment needTeach, then check all the languages that u speaks and increment lang for all languages while keeping track of the maxSpeaker
Once we finish checking all the friendships, we return our answer
The answer is needTeach - maxSpeaker, because for all these people who need to learn a new language, we know that a certain amount of them (maxSpeaker) speak the same language, so for the rest of them who don't, we just teach them the most common language
*/
class Solution {
public:
    bool hasCommonLang(int u, int v, vector<vector<int>> &languages)
    {
        for (int lang: languages[u]) if (find(languages[v].begin(), languages[v].end(), lang) != languages[v].end()) return true;
        return false;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int maxSpeaker = 0, needTeach = 0, s = languages.size();
        vector<int> lang(n); // number of speakers for a certain language
        vector<bool> comm(s, false); // whether a person needs to learn a new language
        for (vector<int> f: friendships)
        {
            int u = f[0]-1, v = f[1]-1; // 1-indexed array, need to -1 for correct index
            if (!hasCommonLang(u, v, languages))
            {
                if (!comm[u])
                {
                    comm[u] = true;
                    needTeach++;
                    for (int l: languages[u])
                    {
                        lang[l-1]++;
                        maxSpeaker = max(maxSpeaker, lang[l-1]);
                    }
                }
                if (!comm[v])
                {
                    comm[v] = true;
                    needTeach++;
                    for (int l: languages[v])
                    {
                        lang[l-1]++;
                        maxSpeaker = max(maxSpeaker, lang[l-1]);
                    }
                }
            }
        }
        return needTeach - maxSpeaker;
    }
};
