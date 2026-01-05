/*
This problem can be solved by simply doing these 3 things:
- Keep track of the number with the smallest absolute value
- Keep track of the number of negative numbers
- Sum up the absolute value of all numbers
We just need to know that if there is an even number of negative numbers, we can just turn all of them into positive numbers
But if there's an odd number of negative numbers, there will be one negative number left no matter how we perform the operation
So, we'll need to minimize the number that will be turned into negative
Do note that we can turn positive numbers into negative for this, so we keep track of the number with the smallest absolute value
0 is also counted as "number with the smallest absolute value"
To keep track of whether there's an even number of negative numbers, I just used a boolean variable isEven, which I XOR with 1 each time a negative number is encountered
I just didn't want to count the actual number of negative numbers
So, as we go through the numbers in the matrix, we first check if it's a negative number
If yes, we toggle the isEven variable and multiply it with -1 to make it positive
Then, no matter if it's a positive or negative number, we add the number to our running sum, and update the smallest number we've seen so far
Once we've finished checking all elements of the matrix, we check if there's an even number of negative numbers
If yes, return the sum as is
If not, return the sum subtracted by twice the smallest number
	- Remember that we need to remove it from our sum AND subtract it from the sum
*/

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        bool isEven = true;
        long long ans = 0;
        int smallest = 100001;
        for (auto &row: matrix)
        {
            for (auto &n: row)
            {
                if (n < 0)
                {
                    isEven ^= 1;
                    n *= -1;
                }
                ans += n;
                smallest = min(smallest, n);
            }
        }
        // cout << isEven << " " << smallest << " " << ans << " " << negSum << endl;
        return (isEven) ? ans : ans - (2 * smallest);
    }
};