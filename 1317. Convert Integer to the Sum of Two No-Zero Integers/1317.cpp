/*
For this problem, we can just start checking all pairs of integers from {1, n-1}
We can stop checking once we've found a pair that fulfills our condition,
or until we reach n/2, since any pair after that would be pairs that we've seen before
For each pair, we check if either digit has 0

We define a function called hasZero, which returns true whenever we find that n % 10 == 0 for any value of n
The value of n is divided by 10 for each iteration
When n goes below 10 and there's still no 0 found, we return the function as false, signifying that there is no 0 for the original digit n

Once we've confirmed that both pairs of digits don't contain 0, we return the pair of numbers as a vector
*/

class Solution {
public:
    bool hasZero(int n)
    {
        if (n % 10 == 0) return true;
        else if (n < 10) return false;
        return hasZero(n/10);
    }
    vector<int> getNoZeroIntegers(int n) {
        for (int i=1; i<=n/2; i++)
        {
            if (!hasZero(i) && !hasZero(n-i)) return {i, n-i};
        }
        return {};
    }
};