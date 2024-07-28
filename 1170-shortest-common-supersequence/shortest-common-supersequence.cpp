class Solution {
public:
    void getLcs(string s1, string s2, int n, int m, vector<vector<int>>&dp)
    {
        for(int i=0; i<=m; i++) dp[0][i] = 0;
        for(int i=0; i<=n; i++) dp[i][0] = 0;

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        getLcs(str1, str2, n, m, dp);

        int i = n;
        int j = m;
        string ans = "";
        while(i > 0 && j > 0)
        {
            if(str1[i-1] == str2[j-1])
            {
                ans = str1[i-1] + ans;
                i--, j--;
            }
            else
            {
                if(dp[i-1][j] > dp[i][j-1])
                {
                    ans = str1[i-1] + ans;
                    i--;
                }
                else 
                {
                    ans = str2[j-1] + ans;
                    j--;
                }
 
            }
        }

        while(i > 0)
        {
            ans = str1[i-1] + ans;
            i--;
        }
        while(j > 0)
        {
            ans = str2[j-1] + ans;
            j--;
        }

        return ans;

    }
};