class Solution {
public:
    int f(int i, int k, vector<int>&nums, vector<vector<int>>&dp)
    {
        if(k == 0) return true;
        if(i == 0) return nums[0] == k;
        if(dp[i][k] != -1) return dp[i][k];
        int notTake = f(i-1, k, nums, dp);
        int take = false;
        if(nums[i] <= k) take = f(i-1, k-nums[i], nums, dp);

        return dp[i][k] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2)
            return false;
        int k = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return f(n - 1, k, nums, dp);
    }
};