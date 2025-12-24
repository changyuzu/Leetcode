/*
This problem can be solved by summing the total number of apples and counting the capacity from the largest
The problem states that apples from the same pack can be distributed into different boxes, so it's not required to find boxes that can fit all the apples in the same pack
Hence, we just need to find the total number of apples across all packs
Then, we subtract the number of apples with the capacity of the boxes to mark that they've been distributed
Since we want the minimum number of boxes, we need to start from the boxes with the largest capacity
To do this more easily, we can sort the capacity vector in decreasing order
Then, while the number of apples is still greater than 0, we keep subtracting with the box capacity and increment our counter
Once there are 0 or less apples, break out of the loop and return the counter
*/

class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int apples = 0, count = 0;
        for (auto &a: apple) apples += a;
        sort(capacity.begin(), capacity.end(), greater<int>());
        for (auto &c: capacity)
        {
            apples -= c;
            count++;
            if (apples <= 0) break;
        }
        return count;
    }
};