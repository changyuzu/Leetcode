/*
For this problem, I decided to use BFS to generate all possible strings from all operations
DFS could also be used, probably, but I just used BFS here
We need a set to keep track of whether we've checked a string, and a queue for the BFS
Initialize ans to the original string, mark it as visited, and push it into the queue
Then, while the queue isn't empty, we generate the strings that we can get from the ADD operation and ROTATE operation separately
If those strings haven't been checked before, add to the queue and mark as visited
Compare ans with each of those generated string, and only keep the lexicographically smallest string using min
Once we've visited all possible strings, return ans
*/

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> vis;
        queue<string> q;
        string ans = s;
        int n = s.size();
        q.push(s);
        vis.insert(s);
        while (!q.empty())
        {
            string curr = q.front();
            q.pop();
            ans = min(ans, curr);

            string added = curr;
            for (int i=1; i<n; i+=2)
            {
                if (added[i] + a > '9') added[i] -= 10 - a;
                else added[i] += a;
            }
            if (vis.find(added) == vis.end())
            {
                q.push(added);
                vis.insert(added);
            }

            string rotated = curr;
            rotate(rotated.begin(), rotated.begin()+b, rotated.end());
            if (vis.find(rotated) == vis.end())
            {
                q.push(rotated);
                vis.insert(rotated);
            }
        }
        return ans;
    }
};