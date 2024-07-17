class Solution {
public:
    int climbStairs(int n) {
        
        if(n <= 2) return n;

        // vector<int>dp(n);
        // dp[0] = 1;
        // dp[1] = 2;
        int prev1(1), prev2(2);

        for(int i=2; i<n; i++)
        {
            int curr = prev1 + prev2;
            prev1 = prev2;
            prev2 = curr;
        }

        return prev2;
    }
};