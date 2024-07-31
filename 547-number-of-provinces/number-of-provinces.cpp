class Solution {
public:
    void dfs(int node, vector<int>&visi, vector<vector<int>>& isConnected)
    {
        visi[node] = true;
        for(int i=0; i<isConnected[node].size(); i++)
        {
            if(isConnected[node][i] == 1 && !visi[i])
            {
                dfs(i, visi, isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        vector<int>visi(isConnected.size(), false);
        int count = 0;

        for(int i=0; i<isConnected.size(); i++)
        {
            if(!visi[i])
            {
                count++;
                dfs(i, visi, isConnected);
            }
        }

        return count;
    }
};