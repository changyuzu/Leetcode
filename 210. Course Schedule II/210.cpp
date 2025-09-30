/*
This is quite similar to 207. Course Schedule
The difference is, in addition to checking for loops, we need to find the order in which to take the courses so we don't have any prerequisite conflicts
So for this problem, we need the adjacency list, a vector to mark visited courses, a vector to mark added courses, and a boolean variable to keep track of whether there's a cycle
I'm using the same approach that I used in 207:
- Check all prerequisites for a course, mark visited courses
- If we find any previously visited course, there's a cycle, so we mark the cycle's existence and return
- If we reach a course with no prerequisite without finding a previously visited course, there's no cycle
	- We add to our answer vector, starting from the topmost item on our recursion stack (the course with no prerequisite) and mark this course as added, then move forward in the prerequisite stack
- At the beginning of each iteration, we check whether we have previously found a cycle, or added the current course, in which case we simply return
When we've finished checking all the courses and their prerequisites, the main body of the function checks whether there's a cycle
If there's a cycle, we return an empty vector, otherwise we return the answer vector
*/

class Solution {
public:
    void check(vector<vector<int>> &adjList, vector<bool> &added, vector<bool> &visited, vector<int> &ans, int idx, bool &cycle)
    {
        if (cycle || added[idx]) return;
        if (visited[idx])
        {
            cycle = true;
            return;
        }
        visited[idx] = true;
        for (int &i: adjList[idx]) check(adjList, added, visited, ans, i, cycle);
        ans.push_back(idx);
        added[idx] = true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList (numCourses);
        for (vector<int> &p: prerequisites) adjList[p[0]].push_back(p[1]);
        vector<bool> added (numCourses, false);
        vector<bool> visited (numCourses, false);
        vector<int> ans;
        bool cycle = false;
        for (int i=0; i<numCourses; i++) check(adjList, added, visited, ans, i, cycle);
        if (cycle) ans = {};
        return ans;
    }
};