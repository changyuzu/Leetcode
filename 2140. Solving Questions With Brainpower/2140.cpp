/*
This question can be solved with dynamic programming
First, we initialize the dp array with size n+1, where n is the size of the questions vector
We use the last element as our boundary check, and declare it as 0
Then, we declare element n-1 as the points you can get from solving the last question
For the dp iteration, we need to start from the back
In order to know whether it's beneficial to solve a problem, we need to know how many points we can get from solving this problem AND the points from future problems
Starting from the back is therefore a more logical solution
So, for each index i in questions, we need to do the following:
- Check whether (i + brainpoweri + 1) is within bounds, using min with n
	- Remember to add 1 because we can only solve the problem AFTER brainpoweri questions
	- The answer is going to be one of 2 possible options, which we'll refer to as the SKIP index:
		- n (index out of bounds, we've set to 0)
		- index within bounds
- Sum the points you can obtain from solving this question AND the dp value from the SKIP index, which gives us the total points you get from this problem
- Decide whether to solve this question by checking whether the total points from this problem is higher than the total points from the next problem, i.e. whether to solve this or skip in favor of the next problem
Once we've checked all the problems, our answer will be stored in the first element of the dp
*/

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        long long dp[n+1];
        dp[n] = 0;
        dp[n-1] = questions[n-1][0];
        for (int i=n-2; i>=0; i--)
        {
            dp[i] = max(questions[i][0] + dp[min(n, i+questions[i][1]+1)], dp[i+1]);
            // min: check whether the next element is within bounds
            // max: check whether it's better to take the current element, or skip in favor of the next one
        }
        return dp[0];
    }
};