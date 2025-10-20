/*
For this problem, we just need to look at index 1 of each string in the vector operations
Since the operation string can only be `++X`, `X++`, `--X`, `X--`, index 1 of the string already shows what operation what we're doing
Keep track of the value of x with each operation, and return x once we've done all the operations
*/

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (string &op: operations) x += (op[1] == '+') ? 1 : -1;
        return x;
    }
};