class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>dist(n, vector<int>(n, 1e9));
        
        for(auto it : edges)
        {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        for(int i=0; i<n; i++) dist[i][i] = 0;

        for(int via=0; via<n; via++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(dist[i][via] == 1e9 || dist[via][j] == 1e9) continue;
                    
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    
                }
            }
        }

        int count = n;
        int res = -1;
        for(int i=0; i<n; i++)
        {
            int temp = 0;
            for(int j=0; j<n; j++)
            {
                if(dist[i][j] <= distanceThreshold)
                {
                    temp++;
                }
            }

            if(temp <= count)
            {
                count = temp;
                res = i;

            }
        }

        return res;
    }
};