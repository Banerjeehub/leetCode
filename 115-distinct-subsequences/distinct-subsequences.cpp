class Solution {
public:
    // int f(int i, int j, string s1, string s2, vector<vector<int>>dp)
    // {
    //     if(j == 0) return 1;
    //     if(i == 0) return 0;

    //     if(s1[i-1] == s2[j-1]) return f(i-1, j-1, s1, s2) + f(i-1, j, s1, s2);
    //     return f(i-1, j, s1, s2);
    // }
    const int mod = 1e9+7;
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(s.length()+1, vector<int>(t.length()+1, 0));
        //return f(s.length(), t.length(), s, t, dp);
        for(int i=0; i<=s.length(); i++)
        {
            dp[i][0] = 1;
        }
        for(int i=1; i<=m; i++)
        {
            dp[0][i] = 0;
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1] == t[j-1])
                {
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
                }
                else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][m];
    }
};