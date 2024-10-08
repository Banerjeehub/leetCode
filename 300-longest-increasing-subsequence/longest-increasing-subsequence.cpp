class Solution {
public:
    int f(int idx, int prev, vector<int>&nums, vector<vector<int>>&dp)
    {
        if(idx == nums.size()) return 0;
        if(dp[idx][prev+1] != -1)
        {
            return dp[idx][prev+1];
        }
        int notTake = f(idx+1, prev, nums, dp);
        int take = INT_MIN;
        if(prev == -1 || nums[idx] > nums[prev])
        {
            take = 1 + f(idx+1, idx, nums, dp);
        }

        return dp[idx][prev+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return f(0, -1, nums, dp);
    }
};