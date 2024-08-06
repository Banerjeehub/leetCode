class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int n = nums.size();

        int target = sum / 2;
        vector<vector<int>>dp(n, vector<int>(target+1, 0));
        vector<int>prev(target+1, 0), curr(target+1, 0);

        

        if(nums[0] <= target) prev[nums[0]] = 1;

        for(int i=1; i<n; i++)
        {
            for(int sum=target; sum>=0; sum--)
            {
                int notTake = prev[sum];
                int take = 0;
                if(nums[i] <= sum)
                {
                    take = prev[sum-nums[i]];
                }

                prev[sum] = take || notTake;

            }
            
        }

        return prev[target];
        
    }
};