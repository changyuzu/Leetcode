/*
There are 2 main ways to solve this problem:
1. Checking whether a number has appeared before in the vector (Solution 1 & 2)
2. Checking the two indexes after a number's appearance in the vector (Solution 3)
The first approach works because all the elements EXCEPT the element that is repeated will only appear once
So, if we see a number appearing more than 1 time, that's our answer
I tried two different ways to store numbers that have been seen before, which I've listed below
The unordered_set doesn't need a set size, while the bitset needs to be initialized to size 10001 because the constraints say `0 <= nums[i] <= 10^4`

The second approach works because for there to be an element that appears n times in a vector of size 2n, it can't be more than 2 indexes apart
Visually:
- A _ A _ A _
- A _ _ A _ A
- A _ _ _ A A (Technically, we'll only check until the last blank before the second to last A, but this case will still be covered with our final check)
No matter how we rearrange the elements, at least 2 instances of the A's will be within two indexes of each other
The only edge case is when there are only 2 or 3 instances of A, and the first one is placed in the first index while the others are placed all the way in the back
When we check for elements that can't be more than 2 indexes apart, we will stop our check at index n-3, which won't reach the last instances of A
But since we already know this to be the case, we can simply return the element at the last index to handle this situation
*/

/*
Solution 1: Unordered set to check whether a number has appeared before
*/
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> s;
        for (auto &n: nums)
        {
            if (s.erase(n) == 1) return n;
            s.insert(n);
        }
        return -1;
    }
};

/*
Solution 2: Bitset to check whether a number has appeared before
*/
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        bitset<10001> seen;
        for (auto &n: nums)
        {
            if (seen[n]) return n;
            seen[n] = 1;
        }
        return -1;
    }
};

/*
Solution 3: Checking closest indexes
*/
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        const int n = nums.size();
        for (int i=0; i<n-2; i++)
        {
            if (nums[i] == nums[i+1] || nums[i] == nums[i+2]) return nums[i];
        }
        return nums[n-1];
    }
};