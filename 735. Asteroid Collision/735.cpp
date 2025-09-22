/*
For this problem, we can use a stack, but since we need to return a vector, we can implement the logic of a stack using a vector to save memory
Basically, whenever we encounter a positive number, we simply push to the back of our vector
Whenever we encounter a negative number, we declare a bool variable called explode to keep track of whether our asteroid has exploded, and start checking the vector from the back:
- If the last element of the vector is larger than the absolute value of the current asteroid, this asteroid explodes, and we break out of the loop
- Else if the last element is equal to the absolute value of the current asteroid, both this asteroid and the last element explode, so we pop the last element before breaking out of the loop
- Else, the last element is smaller than the absolute value of the current asteroid, so our asteroid survives the explosion, and we pop the last element before checking the next last element
We break out of the loop under these conditions:
- The asteroid has exploded
- The vector is empty
- The last element of the vector is a negative value (Asteroids moving in the same direction won't ever collide)
If, when we exit the loop, the asteroid still hasn't exploded, we add the asteroid to the back of our vector
Once we've finished checking all the asteroids, we return the vector as is
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int &a: asteroids)
        {
            if (a > 0) ans.push_back(a);
            else
            {
                bool explode = false;
                while (!ans.empty() && ans.back() > 0)
                {
                    if (ans.back() > -a)
                    {
                        explode = true;
                        break;
                    }
                    else if (ans.back() == -a)
                    {
                        ans.pop_back();
                        explode = true;
                        break;
                    }
                    else ans.pop_back();
                }
                if (!explode) ans.push_back(a);
            }
        }
        return ans;
    }
};