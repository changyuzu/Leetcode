/*
For this graph problem, we're basically checking for cycles
First, we need the adjacency list the size of the number of courses, to keep track of all prerequisites for each course
We also need a boolean vector to mark whether a certain index has been visited, i.e. whether the course has been taken while checking the prerequisites for one course
Then we have our answer, ans, which is initially true, and will be marked false when we detect a cycle
We start by populating the adjacency list
Then, I have a function called check, which checks for cycles in any course prerequisites
There are 2 conditions where we simply exit the function:
- When we've confirmed that there's a cycle
- When we find a cycle for the first time
If none of those conditions are met, we proceed to the function's main body
We mark the index of our current course as visited, then recursively call the check function for all prerequisites in the adjList for that course
Do note that this will also call the function for prerequisites of the prerequisite courses
If there are no cycle in the prerequisites for this course, we mark the course as not-visited (because a different course might visit this course again)
Then, to save time for future iterations, we can clear the adjList for this course, since we've already confirmed that this course can be taken without any prerequisite conflicts
How do we check for cycles? If, in the middle of checking the prerequisites for one course, we encounter the same course twice, there's a cycle on that course
When this happens, we mark our answer as false (signalling that we can't take all the courses) and exit this iteration
Then, for any future iterations, we see that we've already found a cycle, so we can just exit the function
Last, we return our answer
*/

class Solution {
public:
    void check(vector<vector<int>> &prereq, vector<bool> &visited, vector<vector<int>> &adjList, int idx, bool &ans)
    {
        if (!ans) return;
        if (visited[idx])
        {
            ans = false;
            return;
        }
        visited[idx] = true;
        for (int &i: adjList[idx]) check(prereq, visited, adjList, i, ans);
        visited[idx] = false;
        adjList[idx] = {};
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList (numCourses);
        vector<bool> visited (numCourses, false);
        bool ans = true;
        for (vector<int> &p: prerequisites) adjList[p[0]].push_back(p[1]);
        for (int i=0; i<numCourses; i++) check(prerequisites, visited, adjList, i, ans);
        return ans;
    }
};