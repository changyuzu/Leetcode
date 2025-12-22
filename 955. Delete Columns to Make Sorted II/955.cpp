/*
This problem can be solved by keeping track of whether for a set column, a row's element is less than or greater than the previous element
We need to keep track of two things, for which we can use bitsets:
- Which column to remove
- Whether a row is lexicographically sorted with regard to its previous row
We use two levels of for-loops, with a second for loop in the second layer
First, we iterate through the columns:
- For each row, if the previous columns haven't got this row sorted, and the current column has this row not in a lexicographical order with regard to the previous row, we need to remove this column
	- If we've marked a column to be removed, move straight to the next column
	- Otherwise, we mark the rows by whether or not it has been sorted in previous column iterations, or whether it can be sorted in the current iteration
So we keep track of the columns that need to be removed, while also keeping track of rows that are already sorted in columns that aren't removed
If a row has already been sorted in a previous unremoved column, then it doesn't matter if the current column isn't lexicographically sorted, since the previous columns take precedence
Once we've gone through all the columns, just return the number of bits in the bitset for removed columns
*/

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int m = strs.size(), n = strs[0].size();
        bitset<100> remove, sorted;
        // remove keeps track of columns to remove
        // sorted keeps track of whether a row (string) is sorted with regard to its previous row
        for (int j=0; j<n; j++)
        {
            for (int i=1; i<m; i++)
            {
                if (sorted[i] == 0 && strs[i][j] < strs[i-1][j])
                {
                    remove[j] = 1;
                    break;
                }
            }
            if (remove[j]) continue;
            for (int i=1; i<m; i++) sorted[i] = sorted[i] | (strs[i][j] > strs[i-1][j]);
        }
        return remove.count();
    }
};