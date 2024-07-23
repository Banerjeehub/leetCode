class Solution {
public:
    int f(int i, vector<int>&nums, vector<int>&dp)
    {
        if(i == 0) return nums[i];
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int take = nums[i] + f(i-2, nums,dp);
        int notTake = f(i-1, nums, dp);

        return dp[i] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int s = nums.size();
        vector<int>nums1, nums2;

        for(int i=0; i<nums.size(); i++)
        {
            if(i != 0) nums1.push_back(nums[i]);
            if(i != nums.size()-1) nums2.push_back(nums[i]);
        }
        int m = nums1.size();
        int n = nums2.size();
        vector<int>dp1(m, -1), dp2(n, -1);
        return max(f(m-1,nums1, dp1), f(n-1, nums2, dp2));
    }
};