/*
My attempt makes use of dynamic programming
So we initialize a dp vector of all zeros, the size of 1 + number of wizards
Then for each potion, and each wizard, we do the following:
- Check how long it takes the wizard to make the potion
- Check the starting point
	- Do we start immediately after this wizard finished the previous potion?
	- Or do we wait until the previous wizard has finished the next potion?
	- Whichever happens later is our answer
- So for each wizard, we fill their dp using this formula:
	max(dp[current wizard], dp[previous wizard] + (mana of potion * skill of wizard))
Remember that we start with initial value 0, so for the first potion, we're guaranteed to start after the previous wizard finished
In the following potions, however, we need to also take into account the condition where the next wizard hasn't finished when the previous wizard is done with the next potion, hence the max() condition
After we've checked all the wizards for the current potion, we need to retrace our steps to determine when the previous wizard should finish their potion
We need to do this to ensure that no waiting is involved between potions

I've visualized this using the first example from the problem as below:
skill = [1,5,2,4], mana = [5,1,4,2]

potion 0: mana 5
	formula	end	adjusted
w0	5+0		5
w1	25+5	30
w2	10+5	40
w3	20+40	60

potion 1: mana 1
	formula	end	adjusted
w0	1+5		6	53
w1	5+30	35	58
w2	2+40	42	60
w3	4+60	64	64

potion 2: mana 4
	formula	end	adjusted
w0	4+53	57	58
w1	20+58	78	78
w2	8+78	86	86
w3	16+86	102	102

potion 3: mana 2
	formula	end	adjusted
w0	2+58	60	88
w1	10+78	88	98
w2	4+88	92	102
w3	8+102	110	110

Once we've checked all the potions, we just need to return the last element of the dp
*/

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> dp (n+1, 0);
        for (int p=0; p<m; p++)
        {
            // cout << p << " " << mana[p] << endl;
            for (int w=0; w<n; w++)
            {
                dp[w+1] = max(dp[w+1], dp[w]) + 1LL * mana[p] * skill[w];
            }
            if (p == m-1) break;
            for (int w=n-1; w>=0; w--)
            {
                dp[w] = dp[w+1] - (1LL * mana[p] * skill[w]);
            }
            // for (long long &d: dp) cout << d << " ";
            // cout << '\n';
        }
        return dp[n];
    }
};