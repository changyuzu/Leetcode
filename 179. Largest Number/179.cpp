/*
This problem can be solved by sorting the elements of nums
How do we sort them? We can utilize the following property of concatenation, with strings of integers a, b, and c:
If ab > ba and bc > cb, then it's guaranteed that ac > ca
Take the example of a = 7, b = 30, c = 2
ab = 730, ba = 207, ac = 72, ca = 27
Hence, we prove the property above
So, we put all the elements of nums into a vector of strings, converting the integers to string
Then we use the sort function so that the elements are sorted by the order of its concatenation
Then, to catch cases where the vector is only filled with 0 (e.g. {0,0,0}), we check if the first element of the sorted string vector is "0"
If yes, simply return "0"
Otherwise, we declare an empty string, append all the elements of the string vector, and return it
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numstr;
        for (int &num: nums) numstr.push_back(to_string(num));
        sort(numstr.begin(), numstr.end(), [] (string &a, string &b)
        {
            return (a+b) > (b+a);
        });
        if (numstr[0] == "0") return "0";
        string ans = "";
        for (string &s: numstr) ans += s;
        return ans;
    }
};