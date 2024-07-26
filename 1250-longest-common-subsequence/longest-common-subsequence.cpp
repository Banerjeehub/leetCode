class Solution {
public:
    int f(int i, int j, string s1, string s2, vector<vector<int>>&dp)
    {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j])
        {
            return dp[i][j] =  1 + f(i-1, j-1, s1, s2, dp);
        }
        return dp[i][j] = max(f(i-1, j, s1, s2, dp),f(i, j-1, s1, s2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int t1 = text1.size();
        int t2 = text2.size();
        vector<vector<int>>dp(t1+1, vector<int>(t2+1, 0));
        for(int i=1; i<=t1; i++)
        {
            for(int j=1; j<=t2; j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[t1][t2];
    }
};