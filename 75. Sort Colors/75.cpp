/*
A one-pass solution that uses constant space can be realized by using 2 pointers:
- zero: Keeps track of the index where `0` is last placed, initialized to 0
- two: Keeps track of the index where `2` is last placed, initialized to n-1
We start iterating from index 0, where there are 3 possible cases:
- nums[i] == 0: swap nums[i] and nums[zero], then move both i and zero forward (because all elements to the left of the zero pointer has been checked)
- nums[i] == 2: swap nums[i] and nums[two], then move ONLY two back (because the elements between i and two haven't been checked)
- nums[i] == 1: simply move i forward
Once i has overlapped with two, we can simply stop the loop since all elements after two would be 2
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), zero = 0, two = n-1, i = 0;
        while (i <= two)
        {
            // cout << "Current: " << i << " " << nums[i] << endl;
            if (nums[i] == 0)
            {
                swap(nums[i++], nums[zero++]);
            }
            else if (nums[i] == 2)
            {
                swap(nums[i], nums[two--]);
            }
            else i++;
            // for (int &num: nums) cout << num << " ";
            // cout << endl << zero << " " << two << endl;
        }
    }
};