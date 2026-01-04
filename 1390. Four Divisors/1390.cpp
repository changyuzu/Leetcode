/*
This problem can be solved by basically following these steps:
- Count the number of divisors and the sum of the divisors' values
- Only add the sum of the divisors' values to our answer if there are exactly 4 divisors
There are a few ways we can save time on the calculations:
- We can check for divisors only until the square root of a number
	- Divisors will always appear in pairs, so when we get one smaller number, we can also obtain the larger number
		For example, take 21
			The square root of 21 is about 4.58, so we can just check up until 4
			If an integer i is a divisor of x, then x % i == 0
			From this check, we can see that the divisors less than 4 are only 1 and 3
			Then, if we calculate 21 / 1, we get 21, and 21 / 3 yields 7
			Therefore, we can also get 7 and 21 as the divisors of 21 by checking only until the square root of 21
		What about 4? We know the square root of 4 is 2, but we can't count 2 twice
		So if a number has an integer as its square root, we only count that square root integer once
		But this will definitely happen after exhausting all the options less than the square root, so I put this check at the very end
- We can stop the check once the number of divisors exceed 4 and move to the next number
- We know that for any number x, 1 and x itself will always be its divisor
	- Therefore, for each x in nums, we can initialize the number of divisors as 2 and the sum of divisors as (x+1)
		Technically, if x is 1, then we'd get count = 2 and sum of divisors = 2, which is wrong
		But this doesn't affect the outcome of the code, since we still won't add this to our answer
Once we've finished checking all the numbers in nums, return our answer
*/

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for (auto &n: nums)
        {
            int count = 2, divs = n+1, i = 2;
            while (count <= 4 && i*i < n)
            {
                if (n % i == 0)
                {
                    count += 2;
                    divs += i + (n / i);
                }
                i++;
            }
            if (count > 4) continue;
            if (i*i == n)
            {
                count++;
                divs += i;
            }
            if (count == 4) ans += divs;
        }
        return ans;
    }
};