class Solution {
private:
    bool DFS(int node, vector<int>&visited, vector<int>&pathVisited, vector<int>adj[])
    {
        visited[node] = 1;
        pathVisited[node] = 1;

        for(auto it : adj[node])
        {
            if(!visited[it])
            {
                if(DFS(it, visited, pathVisited, adj)) return true;
            }
            else if(pathVisited[it]) return true;
        }

        pathVisited[node] = 0;
        return false;
    }
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        
        vector<int>adj[V];
        vector<int>visited(V, 0);
        vector<int>pathVisited(V, 0);

        for(auto it : prerequisites)
        {
            adj[it[0]].push_back(it[1]);
        }


        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                if(DFS(i, visited, pathVisited, adj)) return false;
            }
        }

        return true;
    }
};