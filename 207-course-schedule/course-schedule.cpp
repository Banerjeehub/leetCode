class Solution {
public:
    bool dfs(int node, vector<int>& visited, vector<int>& pathVisited, vector<int> adj[]) {
        visited[node] = 1;
        pathVisited[node] = 1;

        for (auto it : adj[node]) {
            if (!visited[it]) {
                if (dfs(it, visited, pathVisited, adj)) return true;
            } else if (pathVisited[it]) {
                // If the node is visited and is also in the current path, cycle detected
                return true;
            }
        }

        pathVisited[node] = 0; // backtrack
        return false;
    }

    bool canFinish(int V, vector<vector<int>>& pre) {
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        vector<int> adj[V];

        // Fix: Build the adjacency list correctly
        for (auto it : pre) {
            adj[it[1]].push_back(it[0]); // it[1] → it[0] because course B is prerequisite for A
        }

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, pathVisited, adj)) return false;
            }
        }

        return true;
    }
};