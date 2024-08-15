class Solution {
public:
    bool f(int i, int j, string &s, string &p, vector<vector<int>>&dp)
    {
        if(i < 0 && j < 0) return true;
        if(i>= 0 && j < 0) return false;
        if(i < 0 && j>=0)
        {
            for(int k=j; k>=0; k--)
            {
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?')
        {
            return dp[i][j] = f(i-1, j-1, s, p, dp);
        }
        else if(p[j] == '*')
        {
            return dp[i][j] = f(i-1, j, s, p, dp) || f(i, j-1, s, p, dp);
        }

        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        
        int ss = s.size();
        int pp = p.size();
        vector<vector<int>>dp(ss, vector<int>(pp, -1));
        return f(ss-1, pp-1, s, p, dp);
    }
};