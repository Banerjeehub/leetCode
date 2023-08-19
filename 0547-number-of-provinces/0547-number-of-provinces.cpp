class Solution {

private:
    void DFS(int node, vector<int>&visited, vector<vector<int>>&adjList)
    {
        visited[node] = 1;

        for(auto it : adjList[node])
        {
            if(!visited[it])
            {
                DFS(it, visited, adjList);
            }
        }
    }
    int getProvinces(vector<int>&visited, vector<vector<int>>&adjList)
    {
        int count = 0;
        for(int i=0; i<visited.size(); i++)
        {
            if(!visited[i])
            {
                count++;
                DFS(i, visited, adjList);
            }
        }

        return count;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected[0].size();
        vector<vector<int>>adjList(V);

        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(isConnected[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        //initializing the visited vector
        vector<int>visited(V, 0);
        return getProvinces(visited, adjList);

    }
};