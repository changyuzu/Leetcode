/*
This problem can be solved using the Euclid's Formula for generating a Pythagorean Triple (a,b,c) using positive integers u and v where:
	a = u^2 - v^2
	b = 2uv
	c = u^2 + v^2
Using this property, we can get the valid square triples without having to calculate any square roots
Worth noting here is the primitive Pythagorean Triple, from which all multiplications of it are also valid Pythagorean Triples
A Triple is primitive if and only if:
	- (u, v) are coprime (share no common divisor other than 1)
	- (u, v) have opposite parity (odd-even or even-odd pair)
Say, for u = 2 and v = 1:
	- 2 and 1 are coprimes and have opposite parity, so the resulting triple is a primitive Pythagorean Triple
	a = 2^2 - 1^2 = 4 - 1 = 3
	b = 2uv = 2 * 2 * 1 = 4
	c = 2^2 + 1^2 = 4 + 1 = 5
	So we get the valid triples (3,4,5) and (4,3,5)
Since all triples obtained by multiplying primitive Pythagorean Triples are also valid Pythagorean Triples, we can then get (6,8,10), (9,12,15), etc.
Note that we can also obtain (6,8,10) from u = 3 and v = 1, but they have the same parity, which means it's not a primitive Pythagorean Triple, and isn't counted twice
So, we just need to check pairs where u*u + v*v are smaller than or equal to n
I do this with 2 for loops
- The first one starts from 2 to the square root of n, which I represented using i*i < n
	- We can stop at (i*i < n) because u*u + v*v needs to be smaller than n, and in order for that to be the case, u*u needs to be smaller than n
- The second one start from 1 and stops at i-1
In the loop, we check if i and j have the same parity and whether their greatest commond divisor is larger than 1
- Check for same parity by subtracting j from i, since j is guaranteed to be smaller than i
	- Subtracting numbers of the same parity will result in a number divisible by 2, or with 0 as the last bit in binary representation
Then, since there can be multiples of the resulting primitive Pythagorean Triple, we first get the result of (n / c), where c is the largest of the square triple (i*i + j*j)
Then, to see how many occurrences of this Triple can occur within the range of n, we calculate it with n / c
Last, since we can switch a and b to get 2 valid triples, we multiple the result of n / c with 2, and add to our answer
Once we've exited the for loop, return the answer
*/

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for (int i=2; i*i<n; i++)
        {
            for (int j=1; j<i; j++)
            {
                // cout << i << " " << j << endl;
                if (((i-j) & 1) != 1 || gcd(i, j) > 1) continue;
                int c = i*i + j*j;
                // cout << c << endl;
                ans += 2 * (n / c);
            }
        }
        return ans;
    }
};