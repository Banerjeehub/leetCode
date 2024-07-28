class Solution {
public:
    int f(int idx, int prev,int n,  vector<int>&arr, vector<vector<int>>&dp)
    {
        if(idx == n) return 0;
        if(dp[idx][prev+1] != -1) return dp[idx][prev+1];
        int notTake = f(idx+1, prev,n, arr, dp);
        int take = INT_MIN;
        if(prev == -1 || arr[prev] < arr[idx]) take = 1 + f(idx+1, idx, n, arr, dp);

        return dp[idx][prev+1] =  max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return f(0, -1, n, nums, dp);
    }
};