/*
This problem can be solved by simply comparing the sum of elements on the left and the right of a certain index
We know that we change directions and decrement whenever we encounter non-zero elements, and we aim to turn all elements to 0
So there are 2 possibilities for this happening:
- Left sum == Right sum -> You can move to the left AND to the right for this index, so add 2 to our answer
- Left sum == Right sum + 1 OR Left sum + 1 == Right sum -> You can only choose to more to the left OR to the right, but NOT BOTH for this index, so add 1 to our answer
The easiest way to keep track of the left and right sums is by utilizing prefix sum
I have 2 different solutions, the first one utilizing extra space with a vector the same size as the original vector, the one commented out
The second one doesn't utilize extra space, and simply keeps track of the sum on the left and right as we go
*/

/*
class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref (n, 0);
        pref[0] = nums[0];
        vector<int> zero;
        if (nums[0] == 0) zero.push_back(0);
        for (int i=1; i<n; i++)
        {
            pref[i] = pref[i-1] + nums[i];
            if (nums[i] == 0) zero.push_back(i);
        }
        int ans = 0;
        for (int &num: zero)
        {
            int diff = pref[n-1] - (2 * pref[num]);
            if (diff == 0) ans += 2;
            else if (diff == 1 || diff == -1) ans += 1;
        }
        return ans;
    }
};
*/

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0, ans = 0;
        for (int &num: nums) right += num;
        for (int i=0; i<n; i++)
        {
            left += nums[i];
            right -= nums[i];
            if (nums[i] != 0) continue;
            if (left == right) ans += 2;
            else if (left + 1 == right || left == right + 1) ans++;
        }
        return ans;
    }
};