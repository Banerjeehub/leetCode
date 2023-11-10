class Solution {
private:
    int longestCommonSubsequence(string &s, string &t, int &n, int &m)
    {
        // int n = s.size();
        // int m = t.size();

        vector<int>prev(m+1, 0);
        vector<int>curr(m+1, 0);

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(s[i-1] == t[j-1]) curr[j] = 1 + prev[j-1];
                else curr[j] = max(curr[j-1], prev[j]);
            }
            swap(prev, curr);
        }
        return prev[m];
    }
public:
    int minDistance(string word1, string word2) 
    {
        
        int n = word1.size();
        int m = word2.size();
        return n+m - 2*longestCommonSubsequence(word1, word2, n, m);

    }
};