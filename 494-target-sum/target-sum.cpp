class Solution {
public:
    int f(vector<int>&nums, int k)
    {
        int n = nums.size();
        vector<int>prev(k+1, 0), curr(k+1, 0);
        if(nums[0] == 0)
        {
            prev[0] = curr[0] = 2;
        }
        else
        {
            prev[0] = curr[0] = 1;
            if(nums[0] <= k) prev[nums[0]] = 1;
        }

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<=k; j++)
            {
                int notTake = prev[j];
                int take = 0;
                if(nums[i] <= j) take = prev[j - nums[i]];

                curr[j] = take + notTake;
            }
            prev = curr;
        }
        return prev[k];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int totSum = accumulate(nums.begin(), nums.end(), 0);
        if(totSum - target < 0 || (totSum - target) % 2 != 0) return 0;

        return f(nums, (totSum - target)/2);
    }
};