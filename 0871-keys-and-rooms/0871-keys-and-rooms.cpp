class Solution {
public:
    void dfs(int node, vector<vector<int>>& rooms,vector<int>&visited )
    {
        visited[node] = 1;
        for(auto it : rooms[node])
        {
            if(!visited[it])
            {
                dfs(it, rooms, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>visited(n, false);
        int counter = 0;
        
        for(int i=0; i<n; i++)
        {
            if(!visited[i]) 
            {
                counter++;
                dfs(i, rooms, visited);
                
            }
        }

        if(counter > 1) return false;
        return true;
    }
};