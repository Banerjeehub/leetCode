class Solution {
public:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& memo)
    {
        if (i < 0 && j < 0) return true;
        if (i >= 0 && j < 0) return false;
        if (i < 0 && j >= 0) 
        {
            for (int k = 0; k <= j; k++)
            {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if (memo[i][j] != -1) return memo[i][j];

        if (s[i] == p[j] || p[j] == '?') 
        {
            return memo[i][j] = f(i - 1, j - 1, s, p, memo);
        }
        else if (p[j] == '*')
        {
            return memo[i][j] = f(i - 1, j, s, p, memo) || f(i, j - 1, s, p, memo);
        }
        return memo[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return f(n - 1, m - 1, s, p, memo);
    }
};