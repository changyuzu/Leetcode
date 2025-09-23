/*
For this problem, we just need to check each dot-separated substring and compare which is larger between version1 and version2
If either one is larger, we return -1 or 1, else we move to the next dot-separated substring, and repeat until we reach the end of both strings
To do this, we can use two pointers to go through both strings at the same time, and a temporary variable to store the value of the current substring (revision)
If one version reaches the end before the other, we default that string's revision value to 0
Then, as we go through the dot-separated substrings, we convert the char / string to integer
You can store the substring as a string and use stoi afterward, or directly store the value into an integer
From my trial runs, storing the value into an integer directly takes up slightly less memory (8.6MB vs. 8.3MB), so that's the approach I use in this code
If version1 is larger than version2, return 1
Else if version1 is less than version2, return -1
Else if both strings have reached the end, we break out of the loop and return 0
Else if either one of the versions haven't reached the end of the string, we keep going
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1 = 0, v2 = 0;
        int n1 = version1.size(), n2 = version2.size(), p1 = 0, p2 = 0;
        while (p1 < n1 || p2 < n2)
        {
            v1 = 0, v2 = 0;
            // cout << p1 << " " << p2 << endl;
            if (p1 != n1)
            {
                while (p1 < n1 && version1[p1] != '.')
                {
                    int c = version1[p1] - '0';
                    v1 = (v1 * 10) + c;
                    p1++;
                }
            }
            // cout << p1 << endl;
            if (p2 != n2)
            {
                while (p2 < n2 && version2[p2] != '.')
                {
                    int c = version2[p2] - '0';
                    v2 = (v2 * 10) + c;
                    p2++;
                }
            }
            // cout << p2 << endl;
            // cout << v1 << " " << v2 << endl;
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;
            else if (p1 == n1-1 && p2 == n2-1) break;
            else
            {
                if (p1 != n1) p1++;
                if (p2 != n2) p2++;
            }
        }
        return 0;
    }
};