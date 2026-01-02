/*
This problem can be solved by trying to increment starting from the end of the vector, and moving forward when needed
So I defined a function called increment, which takes a vector and an index
First, we try to increment the element at that index
If the result is smaller than 10, there is no need to proceed further
Otherwise, the operation carries over to the next index, so we set the value of the element at the current index as 0
If we are currently at index 0, we've arrived at the first digit of the number, so we must insert 1 to the beginning
Otherwise, we call the increment function again on index idx-1
Once we've finished the operation, just return the vector digits
*/

class Solution {
public:
    void increment(vector<int> &d, int idx)
    {
        d[idx]++;
        if (d[idx] > 9)
        {
            d[idx] = 0;
            if (idx == 0) d.insert(d.begin(), 1);
            else increment(d, idx-1);
        }
    }
    vector<int> plusOne(vector<int>& digits) {
        increment(digits, digits.size() - 1);
        return digits;
    }
};