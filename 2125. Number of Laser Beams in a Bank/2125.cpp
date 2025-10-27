/*
This problem can be solved by simply keeping track of the number of security devices on the previous non-empty rows
For any 2 rows i and j, both with security devices, the number of laser beams between row i and j would be the product of the devices on both rows
Each device on row i would have 1 laser beam connected to each device on row j, so there would be count[i] * count[j] laser beams
Now look at condition 2 that determines the laser beams: For each row i where r1 < i < r2, there are no security devices in the ith row.
So whenever we encounter a new row with security devices, the row before our most recent doesn't connect to the new row
Therefore, we only need to keep track of the most recent row, and skip rows that have no security devices
Add the product of the current row and the previous row to our answer, assign the current row count to the previous row count, and reset the current row count to 0
Once we've checked all rows, return ans
*/

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ans = 0, curr = 0;
        for (string &row: bank)
        {
            for (char &ch: row)
            {
                if (ch == '1') curr++;
            }
            if (curr == 0) continue;
            ans += curr * prev;
            prev = curr;
            curr = 0;
        }
        return ans;
    }
};