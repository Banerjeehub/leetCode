class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        //creating adj list
        vector<pair<int, int>>adj[n+1];
        for(auto time : times) adj[time[0]].push_back({time[1], time[2]});


        vector<int>dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        
        pq.push({0, k});
        dist[k] = 0;
        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second;
            if (wt > dist[node]) {
            continue;  // Skip processing this node if it has already been relaxed.
            }

            for(auto adjNode : adj[node])
            {
                int ele = adjNode.first;
                int adjWt = adjNode.second;

                if(adjWt + wt < dist[ele])
                {
                    dist[ele] = adjWt + wt;
                    //count++;
                    pq.push({wt+adjWt, ele});
                }
            }
        }
        int answer = INT_MIN;
        for(int i = 1; i <= n; i++){
            answer = max(answer, dist[i]);
        }
        return (answer != INT_MAX) ? answer : -1;
    }

    
};