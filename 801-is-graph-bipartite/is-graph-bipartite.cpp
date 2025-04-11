class Solution {
public:
    bool bfs(int start, vector<int>&teams, vector<vector<int>>&graph)
    {
        queue<int>q;
        q.push(start);
        teams[start] = 1;

        while(!q.empty())
        {
            auto top = q.front();
            q.pop();

            for(auto it : graph[top])
            {
                if(teams[it] == -1)
                {
                    teams[it] = !teams[top];
                    q.push(it);
                }
                else if (teams[it] == teams[top]) return false;
            }
        }

        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>teams(n, -1);
        for(int i=0; i<n; i++)
        {
            if(teams[i] == -1)
            {
                if(!bfs(i, teams, graph)) return false;
            }
        }

        return true;
    }
};