class Solution {
public:
    bool bfs(int start, vector<int>& teams, vector<int> adj[]) {
        queue<int> q;
        q.push(start);
        teams[start] = 1;

        while (!q.empty()) {
            int top = q.front();
            q.pop();

            for (int neighbor : adj[top]) {
                if (teams[neighbor] == -1) {
                    teams[neighbor] = !teams[top]; // Assign opposite team
                    q.push(neighbor);
                } else if (teams[neighbor] == teams[top]) {
                    return false; // Conflict, not bipartite
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> adj[n + 1];
        for (auto& it : dislikes) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]); // Since it's undirected
        }

        vector<int> teams(n + 1, -1); // -1 means not assigned

        for (int i = 1; i <= n; ++i) {
            if (teams[i] == -1) {
                if (!bfs(i, teams, adj)) return false;
            }
        }

        return true;
    }
};