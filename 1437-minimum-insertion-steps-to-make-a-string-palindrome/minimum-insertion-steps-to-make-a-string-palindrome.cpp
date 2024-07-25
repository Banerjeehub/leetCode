class Solution {
public:
    int f(int i, int j, string s1, string s2, vector<vector<int>>&dp)
    {
        if(i < 0 || j<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] =  1 + f(i-1, j-1, s1, s2, dp);
        return dp[i][j] =  max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp)); 
    }
    // int tabulation(string s1, string s2)
    // {
    //     int n = s1.size();
        
    //     vector
    // }
    int minInsertions(string s) {
        int n = s.size();
        string temp = s;
        reverse(temp.begin(), temp.end());
        // int lcs = f(n-1, n-1, s, temp, dp);
        // return s.size() - lcs;


        vector<vector<int>>dp(n+1, vector<int>(n+1, -1)); // O(n * n) + O(n)
        vector<int>prev(n+1, 0), curr(n+1, 0);

        

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(s[i-1] == temp[j-1])
                {
                    curr[j] = 1 + prev[j-1];
                }
                else
                {
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }

        int lcs = prev[n];

        return s.size() - lcs;

    }
};