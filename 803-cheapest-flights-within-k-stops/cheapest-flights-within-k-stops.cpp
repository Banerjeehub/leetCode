class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>>adj[n];

        for(auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>>pq;
        vector<int>dist(n, 1e9);
        pq.push({0, {src, 0}});
        dist[src] = 0;

        while(!pq.empty())
        {
            auto top = pq.front();
            pq.pop();

            int steps = top.first;
            int base = top.second.first;
            int currDist = top.second.second;
            if (steps > k) continue;

            for(auto it : adj[base])
            {
                int node = it.first;
                int eW = it.second;
                if(dist[node] > eW + currDist)
                {
                    dist[node] = eW + currDist;
                    pq.push({steps+1, {node, eW + currDist}});
                }
            }
        }

        if(dist[dst] == 1e9) return -1;
        return dist[dst];

    }
};