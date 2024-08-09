class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // Initialize DP table with 0s
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (const string& str : strs) {
            int zeros = count(str.begin(), str.end(), '0');
            int ones = str.size() - zeros;

            // Traverse dp table in reverse to avoid overwriting results
            for (int i = m; i >= zeros; --i) {
                for (int j = n; j >= ones; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }

        return dp[m][n];
    }
};