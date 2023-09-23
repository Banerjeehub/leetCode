#define vib vector<bool>
class Solution {
private:
    int time = 1;
    void dfs(int node ,int parent, vib &visited, int tin[], int low[], vector<int>adj[], 
             vector<vector<int>>&edges)    {
        visited[node] = 1;
        tin[node] = low[node] = time++;
        for(auto it : adj[node])
        {
            if(it == parent) continue;
            if(!visited[it])
            {
                dfs(it, node, visited, tin ,low, adj, edges);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]) 
                {
                    edges.push_back({it, node});
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
        
        vector<int>adj[n];
        for(auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vib visited(n, 0);
        int tin[n], low[n];
        vector<vector<int>>edges;
        dfs(0, -1, visited, tin, low, adj, edges);
        return edges;
    
    }
};