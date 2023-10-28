class Solution {
private:
    bool helper(vector<vector<int>>&graph, vector<int>&color, int start)
    {
        queue<int>q;
        q.push(start);
        color[start] = 0;


        while(!q.empty())
        {
            auto top = q.front();
            q.pop();


            for(auto it : graph[top])
            {
                if(color[it] == -1)
                {
                    color[it] = ! color[top];
                    q.push(it);
                }
                else if(color[it] == color[top]) return false;
            }


            
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int v = graph.size();
        vector<int>color(v, -1);

        for(int i=0; i<v; i++)
        {
            if(color[i] == -1)
            {
                if(!(helper(graph, color, i))) return false;
            }
        }

        return true;
    }
};