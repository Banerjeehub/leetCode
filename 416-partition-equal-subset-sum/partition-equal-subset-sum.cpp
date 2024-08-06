class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int n = nums.size();

        int target = sum / 2;
        vector<vector<int>>dp(n, vector<int>(target+1, 0));

        for(int i=0; i<n; i++)
        {
            dp[i][0] = 1;
        }

        if(nums[0] <= target) dp[0][nums[0]] = 1;

        for(int i=1; i<n; i++)
        {
            for(int sum=0; sum <= target; sum++)
            {
                int notTake = dp[i-1][sum];
                int take = 0;
                if(nums[i] <= sum)
                {
                    take = dp[i-1][sum-nums[i]];
                }

                dp[i][sum] = take || notTake;

            }
        }

        return dp[n-1][target];
        
    }
};