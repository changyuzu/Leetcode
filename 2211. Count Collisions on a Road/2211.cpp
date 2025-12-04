/*
At first glance, this problem seems like it requires a stack, but we can actually solve this with O(1) space
We know that the leftmost cars that go left will not collide, and the rightmost cars that go right will not collide
So, leading left and trailing right cars can be ignored
Then, for all the cars in between, we actually only need to count the cars that go left or right
The problem statement makes it sound like stationary cars are important, but they actually aren't
- Two cars moving in opposite directions increases 2 collisions -> we count the cars going left AND going right
- A moving car collides with a stationary car increases 1 collision -> we only count the moving car
We can prove this using the string "RSL"
Car 0 (R) goes right and collides with Car 1 (S) -> collision + 1
Car 2 (L) goes left and collides with Car 1 (S) -> collision + 1
Now try removing S, so the string becomes "RL"
Car 0 (R) goes right and collides with Car 1 (L) -> collision + 1
Car 1 (L) goes right and collides with Car 0 (R) -> collision + 1
Hence, we've proven that in truth, we only need to count the number of moving cars, i.e. the Rs and Ls
So, we just need to find the first index without leading Ls, and the last index without trailing Rs, and check the characters between these indexes to count the R and L
Once we've counted the Rs and Ls, return the total
*/

class Solution {
public:
    int countCollisions(string directions) {
        const int n = directions.size();
        int l = 0, r = n-1, ans = 0;
        while (l < n && directions[l] == 'L') l++;
        while (r >= 0 && directions[r] == 'R') r--;
        for (int i=l; i<=r; i++)
            if (directions[i] == 'L' || directions[i] == 'R') ans++;
        return ans;
    }
};