class Solution {
public:
    int f(int i, vector<int>&nums, vector<int>&dp)
    {
        if(i == 0) return nums[i];
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i] + f(i-2, nums, dp);
        int two = f(i-1, nums, dp);

        return dp[i] = max(take, two);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n, -1);
        // return f(n-1, nums, dp);
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        vector<int>dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);

        for(int i=2; i<n; i++)
        {
            int take = nums[i] + dp[i-2];
            int notTake = dp[i-1];

            dp[i] = max(take, notTake);
        }

        return dp[n-1];

        
    }
};