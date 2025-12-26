/*
This problem can be solved using prefix sum
The total penalty can be calculated from the sum of hours where the shop is open and no customers come AND hours where the shop is closed and customers come
If we try to iterate through all possible indexes, it would be (the number hours with no customers before closing) and (the number of hours with customers after closing)
Hence, we can use the concept of prefix sum, and keep track of the lowest penalty as we go
We need to keep track of two sums:
- prefN: Prefix sum of N, for the number of open hours with no customers
- sufY: Suffix sum of Y, for the number of closed hours with customers
We'll need 2 for loops to get our answer
In the first one, we're just getting the total number of Y's, which we store in sufY
This will be the initial penalty of closing at hour 0
Initialize minPenalty, for the minimum penalty seen so far, to this value of sufY, and our answer to 0, since the current minPenalty is for index 0
Then we start our second for loop:
- If customers[i] == 'N', this becomes an open hour with no customer, so we increment prefN
- Otherwise, there is one less closed hour with customer, so we decrement sufY
- Calculate the penalty at index i+1, which we obtain with the formula: curr = sufY + prefN
- If the current penalty is lower than minPenalty, update minPenalty with the current penalty, and the answer with i+1
Once we've gone through all the possible indexes, return our answer
*/

class Solution {
public:
    int bestClosingTime(string customers) {
        const int n = customers.size();
        int sufY = 0;
        for (auto &c: customers) if (c == 'Y') sufY++;
        int prefN = 0, minPenalty = sufY, ans = 0;
        // cout << prefN << " " << sufY << " " << minPenalty << endl;
        for (int i=0; i<n; i++)
        {
            if (customers[i] == 'N') prefN++;
            else sufY--;
            int curr = sufY + prefN;
            if (curr < minPenalty)
            {
                minPenalty = curr;
                ans = i+1;
            }
            // cout << i << " " << prefN << " " << sufY << " " << minPenalty << endl;
        }
        return ans;
    }
};