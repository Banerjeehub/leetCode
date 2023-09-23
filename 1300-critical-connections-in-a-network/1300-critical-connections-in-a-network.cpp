#define vib vector<bool>
#define vin vector<int>
#define v2in vector<vector<int>>
class Solution {
private:
    int time = 1;
    void dfs(int node ,int parent, vib &visited, int tin[], int low[], vin adj[], 
             v2in &bridges)    {
        visited[node] = 1;
        tin[node] = low[node] = time++;
        for(auto it : adj[node])
        {
            if(it == parent) continue;
            if(!visited[it])
            {
                dfs(it, node, visited, tin ,low, adj, bridges);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]) 
                {
                    bridges.push_back({it, node});
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
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vib visited(n, 0);
        int tin[n], low[n];
        v2in bridges;
        dfs(0, -1, visited, tin, low, adj, bridges);
        return bridges;
    
    }
};