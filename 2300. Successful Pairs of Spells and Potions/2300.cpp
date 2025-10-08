/*
This problem can be solved using binary search
Basically, for each spell, we need to find how many potions will get it the target strength (product)
If the potions vector is sorted, we can simply perform a binary search to find the point at which the potion became strong enough to get our target strength
So we sort the potions, and in the beginning, find the minimum value (minVal) of potions in order to get the target strength
We need ceiling division of success / s for this, so I used the ceiling division formula:
	ceil(x,y) = x / y + (x % y != 0)	Basically, if x can't be completely divided by y, add 1
Once we have our minVal, we start checking the potions
If the strongest potion is less than the minVal for this spell, we push 0 to our answer and continue to the next spell
Otherwise, we start our binary search, with the left pointer at 0 and right pointer at the last element of potions
While the middle element is still larger than or equal to minVal, we move our right pointer to the left of mid
Otherwise, we move the left pointer to the right of mid
Once we've found the point at which the potions start getting strong enough to meet the target, all the next potions will also meet the target
So we push the distance between that point to the last element to our answer
Once we've finished checking all the spells, return the answer vector
*/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (int &s: spells)
        {
            long long minVal = success / s + (success % s != 0);
            if (potions[m-1] < minVal)
            {
                ans.push_back(0);
                continue;
            }
            int l=0, r=m-1;
            while (l <= r)
            {
                int mid = l + (r-l) / 2;
                if (potions[mid] >= minVal) r = mid-1;
                else l = mid+1;
            }
            ans.push_back(m-l);
        }
        return ans;
    }
};