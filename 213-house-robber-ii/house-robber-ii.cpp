class Solution {
public:
    int f(vector<int>&nums, vector<int>&dp)
    {
        int n = nums.size();
        if (n == 1) return nums[0];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<nums.size(); i++)
        {
            int take = nums[i] + dp[i-2];
            int notTake = dp[i-1];

            dp[i] = max(take, notTake);
        }

        return dp[nums.size()-1];
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
        return max(f(nums1, dp1), f(nums2, dp2));
    }
};