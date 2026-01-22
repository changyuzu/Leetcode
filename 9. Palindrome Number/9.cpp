/*
This problem can be solved by using a separate variable to get the numbers from x in reverse
With this method, there's no need to convert the integer into a string
But before we do that, there are 2 conditions where we can immediately return false:
- When a non-zero number ends with 0 (i.e. x % 10 == 0) -> We can't have leading 0's in integer
- When a number is smaller than 0 -> We can't have '-' at the end of an integer
If both conditions pass, we proceed with reversing the number, only up until the middle of the number
Start by declaring an integer to 0 (I call the variable rev in the code)
Then, while rev is smaller than x, we keep putting the last digit of x to rev, and divide x by 10
	For rev, the formula becomes: rev = (rev * 10) + (x % 10)
The while loop will stop once rev either becomes equal to or more than x
There are two cases for palindrome numbers:
- The number has even digits
	Take 1221 for example
	The while loop will exit with rev = 12, x = 12
	So we can check that 1221 is a palindrome using (rev == x)
- The number has odd digits
	Take 121 for example
	The while loop will exit with rev = 12, x = 1
	In this case, we need to remove the odd digit at the center
	So we can check that 121 is a palindrome using (rev/10 == x)
So, we just need to return whether the resulting rev and x fulfill the above conditions
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x > 0)) return false; 
        int rev = 0;
        while (rev < x)
        {
            rev = (rev * 10) + (x % 10);
            x /= 10;
        }
        // cout << rev << " " << x << endl;
        return rev == x || rev/10 == x;
    }
};