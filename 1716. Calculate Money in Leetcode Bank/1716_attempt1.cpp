/*
My original attempt is a brute-force approach
I kept track of the values for each day in a fixed-size array of size 7, for each day of the week
Start by counting how many full weeks (cycles) we have, and how many days are left in the remaining week, in case it's not a full week
Then, for each of the remaining days, set arr[i] = i+1
After getting all the remaining days, we go through the cycles
For each day of the week, in each cycle, we do the following:
- If arr[i] == 0, we set arr[i] as i+1
- Otherwise, we incremenent arr[i]
No matter which value we set for arr, we need to add arr[i] to our ans
Once we've got the answer, return ans
*/

class Solution {
public:
    int totalMoney(int n) {
        int cycles = n / 7, rem = n % 7;
        int arr[7] = {0};
        int ans = 0;
        for (int i=0; i<rem; i++)
        {
            arr[i] = i+1;
            ans += arr[i];
        }
        for (int i=0; i<7; i++)
        {
            for (int j=0; j<cycles; j++)
            {
                if (arr[i] == 0) arr[i] = i+1;
                else arr[i]++;
                ans += arr[i];
            }
        }
        // for (int &a: arr) cout << a << endl;
        return ans;
    }
};