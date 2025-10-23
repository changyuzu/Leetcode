/*
For this problem, brute force is enough, so I simply simulated the problem as described
While s.size > 2, keep repeating the for loop as below:
- For each index [0..n-1], s[i] = s[i] + s[i+1] % 10
	- Remember that the digits are originally in a string, so convert to char
- Remove the last element of the vector, reducing the size by 1
Once the size of the string is 2, check whether s[0] is equal to s[1] and return
*/

class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2)
        {
            int n = s.size();
            for (int i=0; i<n-1; i++)
            {
                s[i] = ((s[i] + s[i+1]) % 10) + '0';
            }
            s.pop_back();
        }
        // for (char &c: s) cout << c << endl;
        return s[0] == s[1];
    }
};