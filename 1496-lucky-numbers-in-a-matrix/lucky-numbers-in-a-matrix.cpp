class Solution {
public:
    bool check(int row, int col, int val, int n, int m, vector<vector<int>>& matrix)
    {
        //bool check1(false), chechk2(false);
        for(int i=0; i<m; i++)
        {
            if(val > matrix[row][i]) {
                return false;
            }
        }
        for(int i=0; i<n; i++)
        {
            if(val < matrix[i][col]) {
                return false;
            }
        }

        return true;
    }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>ans;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(check(i, j, matrix[i][j], n, m, matrix))
                {
                    ans.push_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};