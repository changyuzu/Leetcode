/*
This problem can be solved by simply keeping track of the number of plants between two valid sections
A valid section is any section which contains two seats
We don't need to care about the plants in between two seats in the same section
Just look at the plants between the last seat of the previous section AND the first seat of the next section
There can only be multiple ways to divide 2 sections if there is at least 1 plant between the two sections, otherwise there is only one
Since we need to divide the corridor into non-overlapping sections, we can always view two seats as a section
We don't need to consider cases where a seat is considered a part of different sections, since that would make another section not have exactly two seats
Consider the following cases:
- corridor = "SSSS" -> only 1 way to divide, "SS|SS"
- corridor = "SSPSS" -> 2 ways: "SS|PSS", "SSP|SS"
- corridor = "SSPPSS" -> 3 ways, as demonstrated in the problem statement's first example
So, we know that the number of ways to divide 2 sections is 1 + the number of plants between the two sections
When there are multiple sections, the number of ways are multiplied with the previous answer
Therefore, the problem boils down to the product of the number of plants between all sections
Remember to take care of cases where the number of seats is odd, in which case there is no possible way to divide the corridor while ensuring each section has exactly two seats
For me, I just tracked whether the current number of seats is odd or even
I have a separate boolean variable to track whether we've seen a full section before, to ensure that we have AT LEAST 1 valid set, and to ensure we can count the number of plants correctly
Whenever we encounter a seat, I toggle the seats counter by XOR-ing it with 1
If the number of seats is odd, continue
Otherwise, check if we've seen a valid set before
If not, mark that we have now seen a valid set, and continue
If yes, then we count the number of valid ways we can divide the section between the previous section and the current section, by multiplying our answer with (plants + 1)
Remember to apply the modulo operation and reset the plants counter to 0
If we encounter a plant, we only need to start incrementing if we've seen a full set before AND the number of seats is currently even, because we don't care about plants that AREN'T in between two valid sections
Once we've reached the end of the string, check whether we've seen a valid set before AND the number of seats is even
If both conditions are fulfilled, return the answer
Otherwise, there is no way to divide corridor, and return 0
*/

class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        int ans = 1, plants = 0, seats = 0;
        bool first = false; // whether we've seen a full section before
        for (char &ch: corridor)
        {
            if (ch == 'S')
            {
                seats ^= 1;
                if (seats == 1) continue;
                if (!first)
                {
                    first = true;
                    continue;
                }
                // cout << plants << " " << ans << endl;
                ans = (ans * (long) (plants + 1)) % MOD;
                plants = 0;
            }
            else
            {
                if (!first || seats == 1) continue;
                plants++;
            }
        }
        // cout << ans << endl;
        return (!first || seats == 1) ? 0 : ans;
    }
};