class Solution {
public:
    int f(int index, vector<int>&nums, vector<int>&dp)
    {
        if(index == 0) return nums[index];
        if(index < 0) return 0;
        if(dp[index] != -1) return dp[index];
        int pick = nums[index] + f(index-2, nums, dp);
        int notPick = 0 + f(index-1, nums, dp);

        return dp[index] = max(pick, notPick);
    }
int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        vector<int> dp(n, 0);
        
        // Base cases
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        // Fill the dp array
        for (int i = 2; i < n; i++) {
            int pick = nums[i] + dp[i - 2];
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        
        return dp[n - 1];
    }
};