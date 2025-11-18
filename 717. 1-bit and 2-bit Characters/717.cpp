/*
Honestly, understanding this question took longer than solving it
But basically, we just need to iterate through the vector
When we encounter a 0, we move forward 1 step
When we encounter a 1, we move forward 2 steps (because it takes two bits)
We continue until i reaches n-1, where n is the size of the vector
If, after this last operation, i is at n-1, then we return true, otherwise return false
*/

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, n = bits.size();
        while (i < n-1)
        {
            if (bits[i] == 0) i++;
            else i += 2;
        }
        return i == n-1;
    }
};