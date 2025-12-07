/*
This problem can be solved just by knowing that the number of odd numbers between 2 even numbers x and y will always be (x - y) / 2, where x >= y
Then what if x or y turned out to be an odd number? Just add 1 to our answer and move the window inwards (low++ or high--)
This also handles cases where x and y are equal, no matter if they're odd or even numbers
*/

class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;
        if (low % 2 == 1)
        {
            ans++;
            low++;
        }
        if (high % 2 == 1)
        {
            ans++;
            high--;
        }
        return ans + (high - low) / 2;
    }
};