/*
The intuition behind this problem is actually quite simple, the tricky part is handling very large numbers of points
Basically, we just need to count how many points are located on the same plane on each y-axis
The number of trapezoids that can be formed between two y-planes, which have y1 and y2 points on them, is given by the following formula:
	Number of trapezoids = (y1-1 + y1-2 + ... + 1) * (y2-1 + y2-2 + ... + 1)
So, for each y-plane with y points on it, we can have (1 + 2 + ... + y-1) possible lines that can be used to form trapezoids
But calculating this each time is time-consuming
For this, we can utilize the formula for the sum of an arithmetic sequence:
	Sn = (a1 + an) * n / 2
	where a1 is the first term, an is the last term, and n is the number of terms
Since we know that the sequence we count goes from 1 to y-1, the formula becomes:
	Sn = (1 + y-1) * (y-1) / 2 = y * (y-1) / 2	.. (1)
Now we have the formula to get the possible number of lines that can be used to make trapezoids in a given y-plane, what about the number of trapezoids?
We'll need to multiply with the number of possible lines in all the other planes, which can easily give TLE
Say that we have 3 different planes, each with a, b, and c number of possible lines
We need to sum up all the possible combinations, which would be ab, ac, and bc
We can derive another formula for this using this property:
	(a + b + c)^2 = a^2 + b^2 + c^2 + 2 * (ab + bc + ca)
	2 * (ab + bc + ca) = (a + b + c)^2 - ( a^2 + b^2 + c^2)
	ab + bc + ca = [(a + b + c)^2 - ( a^2 + b^2 + c^2)] / 2		.. (2)
So, we can simply keep track of two things before calculating them at the very end:
- The sum of all possible number of lines at each plane
- The sum of the square of all possible number of lines at each plane
Do note that if a y-plane only has 1 point, there's no way to create a trapezoid with this plane, so we can simply skip
The number of points get very large for some test cases, so we need to store the sum of the number of lines and the sum of the squares in long long variables
I tried using long, which still caused overflow
Once we've got all the sums and squares, calculate them according to formula (2), and we're good to go
*/

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> hash;
        for (vector<int> &p: points) hash[p[1]]++;
        long long squares = 0, sums = 0;
        for (auto &[key, val]: hash)
        {
            if (val < 2) continue;
            const long long c = val * (val - 1LL) / 2LL;
            squares += c * c;
            sums += c;
        }
        return (((sums * sums) - squares) / 2) % (int)(1e9 + 7);
    }
};