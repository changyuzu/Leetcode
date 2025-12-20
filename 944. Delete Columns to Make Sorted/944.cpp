/*
This problem is quite straightforward
Just use two for loops to iterate through each column
The outer loop will iterate through the column length, i.e. the length of each string
The inner loop will iterate through the strings
If, at index i, we find two strings x and y (with x coming before y in the vector) where y[i] < x[i], we increment our answer and simply break out of the loop for this column
Once we've checked all columns, return our answer
*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int n = strs[0].size();
        int ans = 0;
        for (int i=0; i<n; i++)
        {
            char ch = strs[0][i];
            for (auto &s: strs)
            {
                if (s[i] < ch)
                {
                    ans++;
                    break;
                }
                ch = s[i];
            }
        }
        return ans;
    }
};