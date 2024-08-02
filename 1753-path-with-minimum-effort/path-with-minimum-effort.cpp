class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>pq;

        vector<vector<int>>diff(n, vector<int>(m, 1e9));

        pq.push({0, {0, 0}});
        diff[0][0] = 0;

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        while(!pq.empty())
        {
            auto top = pq.top();
            int effort = top.first;
            int row = top.second.first;
            int col = top.second.second;
            pq.pop();

            
            if(row == n-1 && col == m-1) return effort;

            for(int i=0; i<4; i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if(nr >= 0 && nr < n && nc >= 0 && nc < m)
                {
                    int newEffort = max(abs(heights[row][col] - heights[nr][nc]), effort);
                    if(newEffort < diff[nr][nc])
                    {
                        diff[nr][nc] = newEffort;
                        pq.push({newEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;

    }
};