class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        string revs = s;
        reverse(s.begin(), s.end());
        int s1 = s.size();
        int s2 = revs.size();
        vector<vector<int>>dp(s1+1, vector<int>(s2+1, 0));

        for(int i=1; i<=s1; i++)
        {
            for(int j=1; j<=s2; j++)
            {
                if(s[i-1] == revs[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[s1][s2];
    }
};