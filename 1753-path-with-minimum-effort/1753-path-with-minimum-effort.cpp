class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int rowSize = heights.size();
        int colSize = heights[0].size();

        vector<vector<int>>diff(rowSize, vector<int>(colSize, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>pq;


        diff[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<int>delRow = {0, 0, 1, -1};
        vector<int>delCol = {1, -1, 0, 0};

        while(!pq.empty())
        {
            int differ = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row == rowSize - 1 and 
               col == colSize - 1) return differ;

            for(int i=0; i<4; i++)
            {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 and newRow < rowSize and 
                   newCol >= 0 and newCol < colSize)
                {
                    int newEffort = max(abs(heights[row][col] - heights[newRow][newCol]), differ);
                    if(newEffort < diff[newRow][newCol])
                    {
                        diff[newRow][newCol] = newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }   
            }   
        } 
        return 0;              
    }
};