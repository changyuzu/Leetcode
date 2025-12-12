/*
This problem can be solved by simply keeping track of when a user comes back online, and counting the number of mentions as specified
I used a vector of int named offline with size numberOfUsers, which keeps track of when a user turns online
Since all users are initially online, each index in offline is initialized to 0
Then, whenever we encounter an Offline Event for user `id`, we simply update offline[id] with timestamp + 60, to signify when a user turns online again
Now, there are a few things to keep in mind:
- The `events` vector is not necessarily sorted
- Events need to be processed in the order of their timestamps
- A user's status change is always processed before any event that occurs in the same timestamp
With those points clarified, we can start coding
First, sort the events by their timestamp
- If Offline and Message Events occur in the same timestamp, Offline comes first
- The timestamps are processed as STRINGS
	- Either use stoi to convert them into integers, or compare the timestamps' size before sorting them by value
Then, we can evaluate all the events
Remember that the answer is a vector of size numberOfUsers, initialized to 0 for all indexes
- If it's an Offline Event for user `id`, update offline[id] to (timestamp + 60)
- Otherwise, it's a Message Event, and we start by checking the mentions
	- If it's "ALL", then increment all indexes
	- If it's "HERE", check the timestamp for this Event, and only increment if the user turns online at this timestamp or earlier
	- Otherwise, increment only for the users mentioned
		- All IDs are separated by a single whitespace, so we can simply check whether each character in mentions_string is a digit or a space
			- If it's a digit, add it to the current calculated ID
			- Otherwise, increment ans for index `id`, and reset `id` to 0
		- Remember that the last ID won't have a space, so we need to increment the answer for that ID at the end
Once we've evaluated all events, return the answer vector
*/

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [] (auto &a, auto &b) {
            return (a[1] == b[1]) ? a[0] > b[0] : (a[1].size() == b[1].size()) ? a[1] < b[1] : a[1].size() < b[1].size();
        });
        // for (auto &e: events) cout << e[0] << " " << e[1] << " " << e[2] << endl;
        vector<int> offline (numberOfUsers);
        vector<int> ans (numberOfUsers);
        for (auto &e: events)
        {
            if (e[0][0] == 'O')
            {
                int time = stoi(e[1]), id = stoi(e[2]);
                offline[id] = time + 60;
            }
            else
            {
                if (e[2][0] == 'A') for (int i=0; i<numberOfUsers; i++) ans[i]++;
                else if (e[2][0] == 'H')
                {
                    int time = stoi(e[1]);
                    for (int i=0; i<numberOfUsers; i++)
                    {
                        if (offline[i] <= time) ans[i]++;
                    }
                }
                else
                {
                    int id = 0;
                    for (char &ch: e[2])
                    {
                        if (ch == ' ')
                        {
                            ans[id]++;
                            id = 0;
                        }
                        else if (isdigit(ch)) id = (id * 10) + (ch - '0');
                    }
                    ans[id]++;
                }
            }
        }
        return ans;
    }
};