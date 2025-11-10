/*
This problem can be solved using a monotonic stack
Funnily enough, when I write the code using an actual stack, the runtime is slower than when I implemented the stack using a vector
Strange, but it works
Anyway, we can visualize the nums vector's elements as heights
[1,3,2,0,1,2,1]
If we look at the values, we'll notice that we can picture how many operations are required to turn all elemnts to 0 by counting the "peaks" of unique values
For example, if we look at subarray [1,3,2] from the above array, we can see that there are 3 "peaks" of unique values: 1, 3, and 2
We can turn 1 into 0 in one operation, 3 in one operation, and 2 in one operation, so that makes 3 operations
What about subarray [1,2,1] from the latter half of the array? There are only 2 "peaks" of unique values: 1 and 2
The second 1 from the above subarray can be turned into 0 in the same operation as the first 1, because they belong to the same "hill"
So, the 1 in subarray index 0 and 2 turn into 0 in one operation, and the 2 becomes 0 in 1 operation
Now you might notice that there are three 1's in the full array [1,3,2,0,1,2,1], at index 0, 4, and 6, why can't we turn the 1 at index 0 in the same operation as the 1's at index 4 and 6?
Look at index 3, there's a "valley" of value 0, which means if we try to do the operation on the full array [1,3,2,0,1,2,1], 0 will be the minimum value, and no change will be made
So we need to take into account the "valleys", and remember that "hills" of the same height with a "valley" between them can't be handled in one operation
Using this intuition, we can use the monotonic stack to keep track of the last value which isn't greater than the current element we're checking
If the next non-greater value in the stack is the same as the current value, it can be reduced to 0 in the same operation (visualize as [1,2,1] at index 2)
But if the next non-greater value in the stack is smaller than the current value, it requires another operation to be reduced to 0 (visualize as [1,3,2] at index 2)
So we need to add 1 to our operation counter, and add the current element to the stack
I put 0 as the first element of the stack prior to any operations, because we only need to look at elements larger than 0
Once we've checked all the elements of nums, return the operations we've done so far
*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        // stack<int> st;
        // st.push(0);
        int ans = 0, n = nums.size();
        vector<int> st;
        st.push_back(0);
        for (int &num: nums)
        {
            while (st.back() > num) st.pop_back();
            if (num > st.back())
            {
                st.push_back(num);
                ans++;
            }
        }
        return ans;
    }
};