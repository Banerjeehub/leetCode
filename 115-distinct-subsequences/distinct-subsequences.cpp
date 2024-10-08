class Solution {
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp)
    {
        if(j == 0) return 1;
        if(i == 0) return 0;    
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i-1] == s2[j-1]) return dp[i][j] =  f(i-1, j-1, s1, s2, dp) + f(i-1, j, s1, s2, dp);
        return dp[i][j] = f(i-1, j, s1, s2, dp);
    }
    const int mod = 1e9+7;
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(s.length()+1, vector<int>(t.length()+1, -1));
        return f(s.length(), t.length(), s, t, dp);

    }
};