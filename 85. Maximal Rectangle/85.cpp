/*
This problem can be solved using the same concept as 84. Largest Rectangle in Histogram, so it's better to solve that problem first
We're basically checking for the largest rectangle at each row
So I used something of a dynamic programming approach combined with the monotonic stack
Since the source matrix uses char instead of int, I used another 2D vector of ints to keep track of the heights
If the current cell is a 1 and its previous row is within bounds, we update the height of the current cell with the formula:
	mat[i][j] = 1 + mat[i-1][j]
Then I apply the same approach as the one used in Problem 84
Use a monotonic stack to keep track of the heights in a strictly increasing order
I used a separate stack for each row
Then, check the area of each rectangle as we move along the column of the current row
It's really just repeating the solution used in Problem 84 on all the rows of the matrix
Once we've finished iterating over all the rows, return the largest area seen so far
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        const int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> mat (m, vector<int> (n));
        int ans = 0;
        for (int i=0; i<m; i++)
        {
            stack<int> st;
            st.push(-1);
            for (int j=0; j<n; j++)
            {
                mat[i][j] = (matrix[i][j] == '1');
                if (mat[i][j] != 0 && i-1 >= 0) mat[i][j] = 1 + mat[i-1][j];
                while (st.top() != -1 && mat[i][st.top()] >= mat[i][j])
                {
                    // cout << st.top() << " " << matrix[i][st.top()] << endl;
                    int height = mat[i][st.top()];
                    // cout << st.top() << " " << matrix[i][st.top()] << " " << height << endl;
                    st.pop();
                    int len = j - st.top() - 1;
                    // cout << i << " " << j << " " << height << " " << len << endl;
                    ans = max(ans, height * len);
                }
                st.push(j);
            }
            while (st.top() != -1)
            {
                int height = mat[i][st.top()];
                st.pop();
                int len = n - st.top() - 1;
                // cout << height << " " << len << endl;
                ans = max(ans, height * len);
            }
        }
        return ans;
    }
};