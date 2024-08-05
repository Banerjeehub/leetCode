class Solution {
public:
    long long f(int i, vector<int>&nums, int x, int parity, vector<vector<long long>>&dp)
    {
        if(i == nums.size()) return 0;
        if(dp[i][parity] != -1) return dp[i][parity];
        long long notTake = f(i+1, nums, x, parity, dp);
        long long take = nums[i] + f(i+1, nums, x, nums[i] % 2, dp);
        if(nums[i] % 2 != parity) take = take - x;

        return dp[i][parity] =  max(take, notTake);
        
    }
    long long maxScore(vector<int>& nums, int x) {
        int n = nums.size();
        vector<vector<long long>>dp(n, vector<long long>(2, -1));
        return nums[0] + f(1, nums, x, nums[0] % 2, dp);
    }
};