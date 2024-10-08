class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int f(int idx, string &s, vector<int>&dp)
    {
        if(idx == s.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        int minCost = INT_MAX;
        for(int i=idx; i<s.size(); i++)
        {
            
            if(isPalindrome(idx, i, s))
            {
                
                int cost = 1 + f(i+1, s, dp);
                minCost = min(minCost, cost);
            }
        }

        return dp[idx] = minCost;

    }
    int minCut(string s) {
        vector<int>dp(s.size(), -1);
        f(0, s, dp);

        return dp[0] - 1;
        
    }
};