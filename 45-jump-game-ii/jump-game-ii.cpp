class Solution {
public:
    long long int f(int idx, vector<int>&nums, vector<int> &dp)
    {
        if(idx >= nums.size()-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        long long int mini = INT_MAX;

        for(int i=1; i<=nums[idx]; i++)
        {
            mini = min(mini, 1+f(idx+i, nums, dp));
        }

        return dp[idx] = mini;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(0, nums, dp);
    }
};