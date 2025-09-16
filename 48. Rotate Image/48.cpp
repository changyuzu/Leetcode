/*
We can achieve a 90 degree clockwise rotation by transposing and then reversing each row of a matrix
For proof, you can just try holding up any rectangular object, like a book
Start by holding it so the longer side is horizontal
Flip it along the diagonal drawn from the top-left to lower-right side of the book, so you have the back of the book facing you, with the longer side now being vertical
To get the front of the book to face you, you simply flip the book along the vertical line
That's pretty much the order we use for our matrix too: transpose, then reverse each row
For the transpose, I use a nested for loop
The outer loop is for all the rows, while the inner loop is for the column
The way I do transpose is by swapping cells along the lower left diagonal, so the inner for loop is limited to when the column is smaller than the row
Then for the reversal, we simply reverse each row in-place
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i=0; i<matrix.size(); i++) for (int j=0; j<i; j++) swap(matrix[i][j], matrix[j][i]);
        for (vector<int> &row: matrix) reverse(row.begin(), row.end());
    }
};