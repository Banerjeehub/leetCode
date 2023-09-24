#define vin vector<int>
#define v2n vector<vector<int>>
#define p push_back
class Solution {
private:    
    int time = 0;
    void dfs(int node, int parent, vin &visi, vin adj[], int tin[], int low[], v2n &bridges)
    {
        visi[node] = 1;
        tin[node] = low[node] = ++time;
        

        for(auto it : adj[node])
        {
            if(it == parent) continue;
            if(!visi[it])
            {
                dfs(it, node, visi, adj, tin, low, bridges);
                low[node] = min(low[it], low[node]);
                if(tin[node] < low[it])
                {
                    bridges.p({it, node});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vin adj[n];

        for(auto it : connections)
        {
            adj[it[0]].p(it[1]);
            adj[it[1]].p(it[0]);
        }
        v2n bridges;
        vin visi(n, 0);
        int tin[n];
        int low[n];
        dfs(0, -1, visi, adj,tin, low, bridges);
        return bridges;

    }
};