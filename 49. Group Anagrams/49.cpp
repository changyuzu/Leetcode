/*
For this problem, we can implement a hash map with the sorted string as the key, and a vector of strings as the value
Taking the strings "tan" and "nat" for example:
- The sorted string for both is "ant"
- We push both "tan" and "nat" to the hash map with key "ant", so the hash map becomes {"ant": {"tan", "nat"}}
After we've gone through every element in strs, we iterate through each key-value pair in the hash map and push the value (a vector of strings) to our answer vector
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (string &s: strs)
        {
            string tmp = s;
            sort(s.begin(), s.end());
            hash[s].push_back(tmp);
        }
        vector<vector<string>> ans;
        for (auto& [key, vec]: hash) ans.push_back(vec);
        return ans;
    }
};