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
        int prev1 = nums[0];
        int prev2 = max(nums[0], nums[1]);
        
        // Fill the dp array
        for (int i = 2; i < n; i++) {
            int curr = max(nums[i] + prev1, prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        
        return prev2;
    }
};