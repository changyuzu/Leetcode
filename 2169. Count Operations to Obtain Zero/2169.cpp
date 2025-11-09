/*
This problem can be solved by simply simulating the operations
To make things easier, we can ensure that num2 is never greater than num1
Then, we use a counter to keep track of the number of operations, which we initialize as 0
While num2 > 0, we do the following:
- Add num1 / num2 to the counter -> That's how many operations can be done using the current num1 and num2
	For example, num1 = 7, num2 = 2; We will add 3 to our counter because we can subtract 2 from 7 for a total of 3 times
- Swap num1 and num2, so num1 now becomes the smaller number
- Assign num2 % num2 to num2, which is our new smaller number
	So, for num1 = 7 and num2 = 2, the new values become num1 = 2, num2 = 1
- Continue the loop with the new value
Once num2 becomes 0, return the counter
*/

class Solution {
public:
    int countOperations(int num1, int num2) {
        if (num2 > num1) swap(num1, num2);
        int c = 0;
        while (num2 > 0)
        {
            c += num1 / num2;
            swap(num1, num2);
            num2 = num2 % num1;
            // cout << num1 << " " << num2 << endl;
        }
        return c;
    }
};