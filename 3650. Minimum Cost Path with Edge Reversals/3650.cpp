/*
This problem can be solved by applying Dijkstra's Algorithm
Start by building the adjacency list, which stores each node's neighbor and the cost to travel to that neighboring node
For the edge reversals, we just need to add the reversed edge with double the weight into the adjacency list
So, for edges[i] = [ui, vi, wi], we add these edges to the adjacency list:
- adjList[ui].push_back({vi, wi})
- adjList[vi].push_back({ui, 2 * wi})
Then, we just need to apply Dijkstra's Algorithm
Dijkstra's Algorithm keeps track of the shortest distance from the source to any of the nodes in the graph
To do this, we utilize a priority_queue of pairs of integers, where each pair is the distance and node number
I named the priority queue pq in the code
	- Using a priority queue ensures that we start evaluating the neighboring nodes from the one with the shortest distance
We also use a vector of size n to store the distance from the source to each of the n nodes, which I name dist in the code
Since node 0 is the source, dist[0] is 0, while all the other nodes are initialized to INT_MAX
We push the source node and its distance to the source node ({0,0}) into the pq
Then, while pq isn't empty:
- Get the topmost element, and store it as the current distance (currd) and current node (currn), then pop from the pq
- Check if the distance of the current node (currn) is shorter than what is currently stored in dist[currd]
	- If not, then we have previously evaluated a shorter path, so we just move onto the next node in the pq
	- If yes, we start evaluating the neighboring nodes of currn
		- For all neighbors listed in adjList[currn], storing the neighbors' values into variables n and w:
			- Moving to node n from currn will cost currd + w
			- If this cost is lower than what is currently stored in dist[n], then the current path is shorter
				- Set currd + w as the new value for dist[n]
				- Push the new value of dist[n] and n into pq, so we can evaluate this path if needed
The distance to the last node will be stored as the last element of dist
Since it's possible that we can't reach the last node, we must first check that dist[n-1] is no longer INT_MAX
If it is still INT_MAX, we return -1, as specified in the problem
Otherwise, return the value of dist[n-1] as is
*/

class Solution {
public:
#define pii pair<int, int>
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pii>> adjList (n); // node, distance
        for (auto &e: edges)
        {
            const int u = e[0], v = e[1], w = e[2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, 2*w});
        }
        vector<int> dist (n, INT_MAX);
        dist[0] = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq; // distance, node
        pq.push({0,0});
        while (!pq.empty())
        {
            auto [currd, currn] = pq.top();
            pq.pop();
            if (dist[currn] < currd) continue;
            for (auto &[n, w]: adjList[currn])
            {
                if (currd + w < dist[n])
                {
                    dist[n] = currd + w;
                    pq.push({dist[n], n});
                }
            }
        }
        // for (auto &i: dist) cout << i << endl;
        return (dist[n-1] == INT_MAX) ? -1 : dist[n-1];
    }
};