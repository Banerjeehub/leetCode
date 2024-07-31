class Solution {
public:
    bool dfs(int node, vector<int>& color, vector<vector<int>>& graph) {
    for (auto it : graph[node]) {
        if (color[it] == -1) {  // If the neighbor has not been colored
            color[it] = 1 - color[node];  // Color it with the opposite color
            if (!dfs(it, color, graph)) return false;  // If the subgraph is not bipartite
        } else if (color[it] == color[node]) {
            return false;  // If a neighboring node has the same color, it's not bipartite
        }
    }
    return true;
}
    bool bg(int start,  vector<int>&color, vector<vector<int>>& graph)
    {
        queue<int>q;
        color[start] = 1;
        q.push(start);

        while(!q.empty())
        {
            int top = q.front();
            q.pop();

            for(int it : graph[top])
            {
                if(color[it] == -1)
                {
                    color[it] = !color[top];
                    q.push(it);
                }
                else if(color[it] == color[top]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int>color(n, -1);

        for(int i=0; i<n; i++)
        {
            if(color[i] == -1)
            {
                if(!dfs(i, color, graph)) return false;

            }
        }
        return true;

    }
};