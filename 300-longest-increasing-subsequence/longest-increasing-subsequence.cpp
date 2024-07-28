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
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); // dp[i][j] means the LIS from index i with the previous index being j

        for (int idx = n-1; idx >= 0; idx--) {
            for (int prev = idx-1; prev >= -1; prev--) {
                int notTake = dp[idx+1][prev+1]; // when not taking the current element
                int take = 0;
                if (prev == -1 || nums[idx] > nums[prev]) {
                    take = 1 + dp[idx+1][idx+1]; // when taking the current element
                }
                dp[idx][prev+1] = max(take, notTake);
            }
        }

        return dp[0][0]; // LIS length starting from the first index
    }
};