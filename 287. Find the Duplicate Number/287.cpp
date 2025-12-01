/*
This problem can be solved usign Floyd's Cycle Finding Algorithm, or the Hare-Tortoise Algorithm, which uses fast-slow pointers
We can imagine the vector nums as a linked list, with nums[i] as the next pointer for any index i
The condition in the problem, where nums contains integers in the range [1..n] with the size of nums being n+1, guarantees that the next pointer will always be contained within nums
So, we start by initializing the slow and fast pointers to nums[0]
Then, while the next iterations of fast and slow aren't equal, we move slow 1 step forward and fast 2 steps forward
By "step", we're referring to how many next items we move forward
1 step forward from i is nums[i], 2 steps forward from i is nums[nums[i]]
When fast and slow point to the same item, we break out of the while loop
Reset slow to nums[0], and we start moving slow and fast forward together, both 1 step at a time
When slow and fast converge again, that will be the duplicate element (the node where the cycle begins), and we just need to return it
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            // cout << slow << " " << fast << endl;
            if (fast == slow) break;
        }
        slow = nums[0];
        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};