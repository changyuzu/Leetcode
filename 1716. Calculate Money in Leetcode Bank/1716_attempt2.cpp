/*
My second attempt makes use of arithmetic progression, mostly the sum formula:
	Sum = (a1 + an) * n / 2
	where a1 is the first element, an is the nth element, n is the number of elements being added
First, we define the number of full weeks as `cycles`, and the remaining days outside the full weeks as `rem`
Let's look at the money we'd get, for n = 24
Week 0: 1+2+3+4+5+6+7	= 28
Week 1: 2+3+4+5+6+7+8	= 35
Week 2:	3+4+5+6+7+8+9	= 42
Week 3: 4+5+6			= 15
Notice that for full weeks, the sum goes up by 7 each week: 28, 35, 42, ...
We can simplify this into an expression: 28 + (7 * i), where i is the week count
For example, in week 0, i is 0, so the sum for week 0 is 28 + (7 * 0)
So, when we're trying to get the sum for the full weeks, we can break it down like this:
- The value 28 doesn't change, so it's just 28 * cycles
- The multiplier to 7 adds up with each cycle, we can make use of the sum formula:
	Sum = (a1 + an) * n / 2 = (cycles - 1) * cycles / 2
	a1 = 0, since in the first week, we don't add by 7
	n = number of full weeks, i.e. cycles
	an = cycles - 1, since we started counting from 0
- Therefore, the formula becomes:
	28 * cycles + (7 * (cycles - 1) * cycles) / 2
But we still have the remaining days outside the full weeks, which we can also solve with the sum formula
Notice that the first element of the week will always be i+1, where i is the week count
Since the number of money increments by one, we can actually deduce that the number of money at day j in week i will always be (i+j)
We can prove this with Week 3: 4+5+6, where the last day, day 3 (1-indexed) is 3+3
Applying this to the sum formula, we get:
	Sum = (a1 + an) * n / 2 = ((cycles + 1 + cycles + rem) * rem) / 2 = ((cycles * 2 + rem + 1) * rem) / 2
	a1 = cycles + 1, since the first day of the week starts from 1
	n = rem, since there are `rem` remaining days to add
	an = (cycles + rem)
Sum up the formulas for the full weeks and the remaining days, and we can get our answer quickly
*/

class Solution {
public:
    int totalMoney(int n) {
        // int cycles = n / 7, rem = n % 7;
        auto [cycles, rem] = div(n, 7);
        return 28 * cycles + (7 * (cycles - 1) * cycles) / 2 + ((cycles * 2 + rem + 1) * rem) / 2;
    }
};