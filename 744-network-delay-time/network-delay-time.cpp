class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n + 1];
        for (auto time : times)
            adj[time[0]].push_back({time[1], time[2]});

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>pq;
            
        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int currDist = top.first;
            int base = top.second;

            if(currDist > dist[base]) continue;

            for(auto it : adj[base])
            {
                int eW = it.second;
                int node = it.first;

                if(dist[node] > eW + currDist)
                {
                    dist[node] = eW + currDist;
                    pq.push({dist[node], node});
                }
            }
        }

        int res = INT_MIN;
        for(int i=1; i<=n; i++)
        {
            res = max(res, dist[i]);
        }

        if(res == INT_MAX) return -1;
        return res;
    }
};