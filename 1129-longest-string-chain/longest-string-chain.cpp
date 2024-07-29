class Solution {
public:
    bool check(string &a, string &b)
    {
        if(a.size() != b.size() + 1) return false;

        int i = 0;
        int j = 0;

        while(i < a.size())
        {
            if(j < b.size() && a[i] == b[j])
            {
                i++, j++;
            }
            else
            {
                i++;
            }
        }
         return j == b.size();
    }
    static bool cmp(const string &a, const string &b)
    {
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), cmp);

        vector<int>dp(n, 1);
        int maxi = 1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(check(words[i], words[j]) && (1 + dp[j] > dp[i]))
                {
                    dp[i] = 1 + dp[j];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};