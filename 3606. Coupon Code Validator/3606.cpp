/*
This problem can be solved by simply filtering out invalid codes, then putting the valid codes in a data structure that allows storing data in pairs, because we also need each code's businessLine
Some of the solutions other people posted used an unordered_map, but I just used a vector of pairs for the holder
But they're using the unordered_map to store the priority of each businessLine, while I stored the code and businessLine as pairs separately
The unordered_map priority implementation would be useful when the ordering is custom, but this problem's businessLine ordering is lexicographical, so I just used a normal sort function
First, we need to filter out invalid codes, checked with the following conditions:
- isActive[i] is false
- code[i] is an empty string
- businessLine[i] isn't in the four specified categories
- code[i] contains characters other than uppercase and lowercase alphabets, digits, and underscores
If the code we're checking passes all those checks, we insert businessLine[i] & code[i] as a pair in our holder vector
Once we've checked all the codes, we sort the holder vector by the following order:
- businessLine ascending lexicographical order
- code ascending lexicographical order
When that's done, we just need to iterate over the holder vector again, only pushing code[i] into our answer vector
Once we've finished the iteration, return ans
*/

class Solution {
public:
#define pss pair<string, string>
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        const int n = code.size();
        vector<string> ans;
        vector<pss> holder; // businessLine, code
        for (int i=0; i<n; i++)
        {
            if (!isActive[i] || code[i] == "" || (businessLine[i] != "electronics" && businessLine[i] != "grocery" && businessLine[i] != "pharmacy" && businessLine[i] != "restaurant")) continue;
            bool flag = false;
            for (char &ch: code[i])
            {
                if (!isalnum(ch) && ch != '_')
                {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            // cout << code[i] << endl;
            holder.push_back({businessLine[i], code[i]});
        }
        sort(holder.begin(), holder.end(), [] (auto &a, auto &b)
        {
            return (a.first == b.first) ? a.second < b.second : a.first < b.first;
        });
        for (auto &h: holder) ans.push_back(h.second);
        return ans;
    }
};