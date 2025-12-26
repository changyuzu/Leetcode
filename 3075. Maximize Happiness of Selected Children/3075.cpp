/*
For this problem, we just need to sort the happiness vector, pick starting from the biggest element, and stop when the happiness - index becomes 0
We know that we're trying to pick k children in k turns, and the children's happiness decreases with each passing turn
In other words, the happiness of the children is subtracted by the turn index where they're picked
So we just need to use a for loop and add the value of happiness[i] - i to our answer, and stop when happiness[i] - i <= 0 since the happiness value can't become negative
Once we've gotten through k turns, or the happiness[i] - i value becomes 0, we break out of the loop and return the answer
*/

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long ans = 0;
        for (int i=0; i<k; i++)
        {
            if (happiness[i] - i <= 0) break;
            ans += happiness[i] - i;
        }
        return ans;
    }
};