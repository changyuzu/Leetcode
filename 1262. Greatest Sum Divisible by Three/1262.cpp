/*
This problem can be solved by simply keeping track of 5 things:
- The sum of all elements in the vector
- The two smallest numbers with mod 3 = 1
- The two smallest numbers with mod 3 = 2
We only need to keep track of these, because we just need to know the total sum, and reduce the least number to get to a number divisible by 3
Why do we need to keep 2 of the smallest numbers with mod 3 = 1 and 2? Because there are two ways we can get num % 3 == 1 numbers to be divisible by 3, same as num % 3 == 2
- For num % 3 == 1, we can make num divisible by 3 by subtracting it with:
	- One other num1 where num1 % 3 == 1
	- Two other num1 and num2 where num1 % 3 == 2 and num2 % 3 == 2
- For num % 3 == 2, we can make num divisible by 3 by subtracting it with:
	- One other num1 where num1 % 3 == 2
	- Two other num1 and num2 where num1 % 3 == 1 and num2 % 3 == 2
So, we can solve this problem with 1 pass over the vector
For all num in nums:
- Add num to our sum
- If num % 3 == 1:
	- Check num against the two smallest mod 1 numbers we had, and update accordingly if needed
- If num % 3 == 2:
	- Check num against the two smallest mod 2 numbers we had, and update accordingly if needed
Once we've finished iterating over the vector, we will have the total sum
If sum % 3 == 0, return sum as is
If sum % 3 == 1, check if it would be better to subtract one mod1 number, or two mod2 numbers, and return the subtracted sum
If sum % 3 == 2, check if it would be better to subtract one mod2 number, or two mod2 numbers, and return the subtracted sum
*/

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0, mod10 = INT_MAX, mod11 = INT_MAX, mod20 = INT_MAX, mod21 = INT_MAX;
        for (int &num: nums)
        {
            sum += num;
            if (num % 3 == 0) continue;
            else if (num % 3 == 1)
            {
                if (num < mod10)
                {
                    mod11 = mod10;
                    mod10 = num;
                }
                else if (num < mod11) mod11 = num;
            }
            else
            {
                if (num < mod20)
                {
                    mod21 = mod20;
                    mod20 = num;
                }
                else if (num < mod21) mod21 = num;
            }
        }
        // cout << sum << endl;
        if (sum % 3 == 0) return sum;
        else if (sum % 3 == 1)
        {
            if (mod21 == INT_MAX) return sum - mod10;
            else return sum - min(mod10, mod20+mod21);
        }
        else
        {
            if (mod11 == INT_MAX) return sum - mod20;
            else return sum - min(mod20, mod10+mod11);
        }
    }
};