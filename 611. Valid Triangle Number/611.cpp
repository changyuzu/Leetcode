/*
For this problem, we need to keep in mind what makes a valid triangle: The sum of two of its sides has to be greater than its third side
So we can sort the vector for convenience, fix one of the numbers, and look for pairs that fulfill the condition above
I iterated through the numbers starting from the third element to get the fixed number
Then apply binary search to the elements on the left of the fixed number
Starting with the left and right pointers right at the edge of the boundary, if the sum of the leftmost number and the rightmost number is greater than the fixed number, then all pairs between the leftmost and rightmost numbers are greater than the fixed number
Therefore, they all fulfill the condition
We add the number of elements in between to the answer count, and move the right pointer to the left
Otherwise, we move the left pointer to the right
Once the left and right pointers meet, we break out of the loop and return the answer
*/

class Solution {
public:
    bool validTriangle(int &a, int &b, int &c)
    {
        // cout << a << " " << b << " " << c << endl;
        if (((a+b) <= c) || ((a+c) <= b) || ((b+c) <= a)) return false;
        else return true;
    }
    int triangleNumber(vector<int>& nums) {
        int ans = 0, n = nums.size();
        if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        for (int i=2; i<n; i++)
        {
            int l = 0, r = i-1;
            while (l < r)
            {
                if (nums[l] + nums[r] > nums[i])
                {
                    ans += (r-l);
                    r--;
                }
                else l++;
            }
        }
        return ans;
    }
};