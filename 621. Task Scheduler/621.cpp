/*
My approach uses hash table and sorting while keeping track of the available space
First, start by counting the frequency of each task
Since the tasks can only be an uppercase English letter, I just used a vector of size 26
Once we've got the frequency of all tasks stored in the vector, I sorted the vector in decreasing order
Then I get the following variables:
- maxFreq: the frequency of the most common task, which we need to get the least number of intervals to complete the most frequent task
- space: the total number of empty spaces between occurrences of the most common task
- ans: our initial answer, which is the frequency of the most common task + the empty space between them
Then, we just need to check whether we can fit the rest of the tasks in the empty space
So we do a for loop for index i = [1..26] (We don't check i=0 because we already went through it with our initial answer)
There are a few cases to consider:
- If freq[i] == 0, all tasks afterward are 0, we can just skip
- If freq[i] == maxFreq, there are 2 possibilities:
	- There are enough idle intervals to fit all but the last occurrence of the task
		- In this case, we just need to add 1 more CPU interval, and reduce the number of spaces by freq[i] - 1
	- We've used up all idle intervals
		- In this case, we add freq[i] to our answer
			We don't need to case about having to ensure there are n intervals between the two occurrences, because we can just put them anywhere between the two occurrences of the most frequent task
			Say we have tasks AAABBCCDD, with n = 2
			If we fill up the CPU interval by task, it would be like this
			A X X A X X A
			A B X A B X A
			A B C A B C A
			A B C D A B C D A
- Else, if the number of available space is greater than freq[i], we can just put all tasks in the available space
	- Reduce the number of available space by freq[i]
- Lastly, there isn't enough space for this task
	- Some of the tasks may fit in the leftover space
	- We just need to add freq[i] - space to our answer
	- Since there isn't even enough space for this task, we will definitely use up all available space, so set space as 0
Once we've gone through all the tasks, return our answer
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq (26, 0);
        for (auto &t: tasks)
        {
            freq[t - 'A']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int maxFreq = freq[0], space = n * (maxFreq - 1), ans = maxFreq + space;
        // cout << ans << endl;
        for (int i=1; i<26; i++)
        {
            if (freq[i] == 0) break;
            int f = freq[i];
            if (f == maxFreq)
            {
                if (space >= f-1)
                {
                    ans++;
                    space -= f-1;
                }
                else ans += f;
            }
            else if (space >= f)
            {
                space -= f;
            }
            else
            {
                f -= space;
                space = 0;
                ans += f;
            }
            // cout << ans << endl;
        }
        return ans;
    }
};