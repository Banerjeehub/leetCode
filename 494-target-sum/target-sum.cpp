class Solution {
public:
    int f(int idx, int amount, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (amount == 0 && nums[idx] == 0)
                return 2;
            if (amount == 0 || nums[idx] == amount)
                return 1;
            return 0;
        }
        if (dp[idx][amount] != -1)
            return dp[idx][amount];

        int notTake = f(idx - 1, amount, nums, dp);
        int take = 0;
        if (amount >= nums[idx]) {
            take = f(idx - 1, amount - nums[idx], nums, dp);
        }

        return dp[idx][amount] = take + notTake;
    }

    int findTargetSumWays(vector<int>& nums, int target) {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();

        int amount = (sum - target) / 2;
        if ((sum - target)%2 == 1)
            return 0;
        if (target > sum)
            return 0;
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n - 1, amount, nums, dp);
    }
};