/*
This problem can be solved by starting to cut down the graph from the outermost nodes
By outermost nodes, I'm referring to nodes with only 1 edge, which points inwards to another node, which could have more than 1 edge
So, we trim the tree by eliminating the outermost nodes, and continue to move inwards until we can't find anymore nodes with only 1 edge
First, we start by checking how many nodes are in the tree
If there is only 1 node, then that node is the MHT root, so simply return {0}
Otherwise, we start building the adjacency list, and keep track of how many edges a node has in a separate vector
Then we also create a queue to keep track of the nodes which only have 1 edge, i.e. the outermost nodes
Fill the queue with the original outermost nodes, then enter a while loop while the queue isn't empty:
- Clear the answer vector
- Push the elements in the queue into the answer vector, decrement the number of edges for the current node
- For all adjacent nodes, reduce the number of edges for those adjacent nodes
	- If the number of edges becomes 1, add the adjacent node into the queue
This repeats until we can't find anymore nodes with only 1 edge
In this case, we keep the answer vector from that iteration and return it as our answer
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        vector<vector<int>> adjList (n);
        vector<int> inDeg (n);
        for (vector<int> &e: edges)
        {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
            inDeg[e[0]]++;
            inDeg[e[1]]++;
        }
        queue<int> q;
        for (int i=0; i<n; i++) if (inDeg[i] == 1) q.push(i);
        vector<int> ans;
        while (!q.empty())
        {
            ans.clear();
            int n = q.size();
            while (n--)
            {
                int curr = q.front();
                q.pop();
                ans.push_back(curr);
                inDeg[curr]--;
                for (int &adj: adjList[curr])
                {
                    inDeg[adj]--;
                    if (inDeg[adj] == 1)
                    {
                        q.push(adj);
                    }
                }
            }
        }
        return ans;
    }
};