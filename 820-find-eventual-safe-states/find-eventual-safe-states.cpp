class Solution {
public:
    bool dfs(int node, vector<int>&visited, vector<int>&pathVisited, vector<vector<int>>&adj)
    {
        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                if(dfs(it, visited, pathVisited, adj))
                {
                    return true;
                }
            }
            else if(pathVisited[it]) return true;
        }

        pathVisited[node] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int V = graph.size();
        vector<vector<int>>adj(V);

        for (int i = 0; i < V; i++) {
            for (int it : graph[i]) {
                adj[i].push_back(it);
            }
        }

        vector<int>visited(V, 0);
        vector<int>pathVisited(V, 0);
        vector<int>ans;

        for(int i=0; i<V; i++)
        {
            if(!visited[i]) dfs(i, visited, pathVisited, adj);
        }

        for(int i=0; i<V; i++)
        {
            if(!pathVisited[i]) ans.push_back(i);
        }

        return ans;
    }
};