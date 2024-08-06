class Solution {
public:
    bool f(int i, int target, vector<int>&nums, vector<vector<int>>&dp)
    {
        if(target == 0) return 1;
        if(i == 0) return target == nums[0];
        if(dp[i][target] != -1) return dp[i][target];
        int notTake = f(i-1, target, nums, dp);
        int take = 0;
        if(nums[i] <= target)
        {
            take = f(i-1, target - nums[i], nums, dp);
        }

        return dp[i][target] = take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int n = nums.size();

        int target = sum / 2;
        vector<vector<int>>dp(n, vector<int>(target+1, -1));
        return f(n-1, target, nums, dp);
    }
};