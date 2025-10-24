/*
This was my first Segment Tree problem, which was the Daily Question in August, I think it was August 6?
I had to look at other people's answers to solve the problem back then, but I'm proud to say I wrote all the code below by myself
So, for the segment tree, we first need to find the size
To avoid overlapping indexes as we go up the levels of the nodes, we need at least twice the number of the power of 2 larger than the size of the baskets vector
Once we have the appropriate size, we create our segment tree, which I named fen for fenwick tree in the code
Then I put the original values of baskets in the latter half of the tree
The `fill` function fills the fenwick tree starting from the middle point, going towards 0
Each inner node is filled with the max of the outer 2 nodes, and we can leave fen[0] as 0 since we only need to check starting from 1
So, for baskets = [3,5,4], the segment tree would be: [0,5,5,4,3,5,4,0]
Node that fen[1] would be the largest element in the segment tree
Then, in the main function, we do the following for each fruit in `fruits`:
- If fruit is larger than fen[1], none of the baskets could contain that fruit, so increment our answer counter and continue to the next fruit
- Otherwise, we search for the leftmost basket that can contain the fruit
	- The `find` function is defined so, starting from index 1, it checks the next level of nodes for the leftmost node that fulfills fen[idx] >= fruit
	- The while loop is set so it only keep going while the index is in the first half of the fenwick tree, and will exit once idx reaches the latter half (the original baskets elements)
- Once we've found the index of the basket, we change the value of fen[idx] to 0 so it doesn't get used again
- Remember that we need to update the upper levels of the segment tree, which is where the `update` function comes in
	- Starting from index = idx/2 to signify the original index's next level, we check for the max value of the nodes that share the same root as idx and store it as tmp
	- If fen[idx] is different from tmp, update fen[idx], and move upward by dividing idx with 2
	- Otherwise, the upper levels won't be affected by the changes in the lower levels, so we can stop
Once we've finished checking all the fruits, we can simply return the answer counter
*/

class Solution {
public:
    void update(vector<int> &fen, int idx)
    {
        while (idx > 0)
        {
            int tmp = max(fen[idx*2], fen[(idx*2)+1]);
            if (fen[idx] == tmp) break;
            fen[idx] = tmp;
            idx /= 2;
        }
        // for (int &f: fen) cout << f << " ";
        // cout << endl;
    }
    void fill(vector<int> &fen, int idx)
    {
        while (idx > 0)
        {
            fen[idx] = max(fen[idx*2], fen[(idx*2)+1]);
            idx--;
        }
    }
    int find(vector<int> &fen, int &len, int &val)
    {
        int idx = 1;
        while (idx < len)
        {
            if (fen[idx*2] >= val) idx *= 2;
            else idx = (idx*2) + 1;
        }
        return idx;
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size(), len = 1;
        while (len < n) len <<= 1;
        vector<int> fen (len*2, 0);
        for (int i=0; i<n; i++) fen[i+len] = baskets[i];
        fill(fen, len-1);
        // for (int &f: fen) cout << f << " ";
        // cout << endl;
        int ans = 0;
        for (int &fruit: fruits)
        {
            if (fruit > fen[1]) ans++;
            else
            {
                int idx = find(fen, len, fruit);
                // cout << fruit << " " << idx << " " << fen[idx] << endl;
                fen[idx] = 0;
                update(fen, idx/2);
            }
        }
        // for (int &f: fen) cout << f << " ";
        return ans;
    }
};