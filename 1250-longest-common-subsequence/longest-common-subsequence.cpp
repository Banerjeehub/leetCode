class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp)
    {
        if(i < 0 || j < 0) return 0;
        //if(i == 0 && j == 0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j])
        {
            dp[i][j] = 1 + f(i-1, j-1, s1, s2, dp);
        }
        else
        {
            dp[i][j] = max(f(i-1, j, s1,s2, dp), f(i, j-1, s1, s2, dp));
        }

        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size(), vector<int>(text2.size(), -1));
        int t1 = text1.size();
        int t2 = text2.size();
        return f(t1-1, t2-1, text1, text2, dp);
    }
};