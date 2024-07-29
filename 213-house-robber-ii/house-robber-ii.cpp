class Solution {
public:
    int f(int i, vector<int>&nums, vector<int>&dp)
    {
        if(i < 0) return 0;
        if(i == 0) return nums[i];

        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + f(i-2, nums, dp);
        int notPick = f(i-1, nums, dp);

        return dp[i] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        
        vector<int>nums1, nums2;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums.size() == 1) return nums[0];
            if(i != 0) nums1.push_back(nums[i]);
            if(i != nums.size()-1) nums2.push_back(nums[i]);
        }

        int n = nums1.size();
        int m = nums2.size();
        vector<int>dp1(n+1, -1), dp2(m+1, -1);

        return max(f(n-1, nums1, dp1), f(m-1, nums2, dp2));
    }
};