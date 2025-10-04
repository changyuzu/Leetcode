/*
This problem was quite initimidating for me at first, and the first time I worked on it last month, I ended up having to check other people's solutions
But this time, I was able to solve it in 35m 42s without checking other people's work or my past submission, which makes me happy

So, basically we're going to treat the equations as a directed graph, with edges going both ways between each pair of vertices
For example, if we have equation = ["a","b"] with value = 2.0, we're going to store the value of a/b = 2, as well as b/a = 1/2 = 0.5
Since the equations are strings, we can't really use a vector with fixed size, so I opted for an unordered_map for the adjacency list
The key of the unordered_map is the numerator, while the value is a vector of pairs, in which each pair is the denominator and the division result
We also need another unordered_map to mark whether we've visited a vertex in an iteration
Start by filling up the adjacency list, and also the visited map with default falue false
Then, for all the queries, we start checking from the adjacency list of the numerator

I declared a helper function called check, which returns a boolean value representing whether we were able to find our target denominator
If, at any point, the current value being checked matches with the target denominator, we mark the current product as our answer and return true
But if we encounter a previously visited vertex, we return false
The main body of the function marks the current node as visited
I use a temporary boolean value named tmp to keep track of whether any of the following values ever resulted in the target denominator
Then, for each value in the adjacency list of the current denominator, we call the check function and OR the result with the tmp variable
Do keep in mind that this will also check all values in the adjacency list of the current denominator's adjacency list
Once we've finished checking all vertices of the current value, we mark it as not visited again to avoid conflict with future iterations
Then we return tmp, which should be true if any of the values ended up being the target denominator

In the main body, we call the check function for all values in the adjacency list of the numerator
I declared a bool variable called added to keep track of whether we've added anything for the current query
If one value returns true, we push the product to our answer vector, mark added as true, and break out of the loop
If, after checking all values in the adjacency list, we haven't added anything for the current value, we push -1 to the answer vector
Once we've checked all queries, return the answer vector
*/

class Solution {
public:
#define psd pair<string,double>

    bool check(string &num, string &den, string curr, double prod, double &p, unordered_map<string, vector<psd>> &adjList, unordered_map<string, bool> &visited)
    {
        // cout << num << " " << den << " " << curr << endl;
        if (curr == den)
        {
            p = prod;
            return true;
        }
        if (visited[curr]) return false;
        bool tmp = false;
        visited[curr] = true;
        for (auto [str, val]: adjList[curr]) tmp |= check(num, den, str, prod * val, p, adjList, visited);
        visited[curr] = false;
        return tmp;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<psd>> adjList;
        unordered_map<string, bool> visited;
        int n = values.size();
        for (int i=0; i<n; i++)
        {
            adjList[equations[i][0]].push_back({equations[i][1], values[i]});
            adjList[equations[i][1]].push_back({equations[i][0], 1/values[i]});
            visited[equations[i][0]] = false;
            visited[equations[i][1]] = false;
        }
        n = queries.size();
        vector<double> ans;
        for (vector<string> &q : queries)
        {
            double p = 0; bool added = false;
            for (auto [str,val]: adjList[q[0]])
            {
                if (check(q[0], q[1], str, val, p, adjList, visited))
                {
                    ans.push_back(p);
                    added = true;
                    break;
                }
            }
            if (!added) ans.push_back(-1);
        }
        return ans;
    }
};