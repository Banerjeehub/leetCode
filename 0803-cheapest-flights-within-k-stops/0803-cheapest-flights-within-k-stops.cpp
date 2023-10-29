class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>>adj[n];

        for(auto flight : flights)
        {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        queue<pair<int, pair<int, int>>>q;
        vector<int>prices(n, 1e9);
        q.push({0, {src, 0}});

        prices[src] = 0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int source = it.second.first;
            int cost = it.second.second;

            for(auto i : adj[source])
            {
                int adjNode = i.first;
                int adjPrice = i.second;

                if(adjPrice + cost < prices[adjNode] && stops <= k)
                {
                    prices[adjNode] = adjPrice + cost;
                    q.push({stops+1, {adjNode, prices[adjNode]}});
                }
            }


        }

        if(prices[dst] == 1e9) return -1;
        return prices[dst];

    }
};