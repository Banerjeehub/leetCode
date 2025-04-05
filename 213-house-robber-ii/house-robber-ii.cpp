class Solution {
public:
    int rob(int idx, vector<int>&nums, vector<int>&dp)
    {
        if(idx < 0) return 0;
        if(idx == 0) return nums[0];
        if(dp[idx] != -1) return dp[idx];

        int take = nums[idx] + rob(idx-2, nums, dp);
        int notTake = rob(idx-1, nums, dp);

        return dp[idx] =  max(take, notTake);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int>nums1, nums2;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(i != 0) nums1.push_back(nums[i]);
            if(i != nums.size()-1) nums2.push_back(nums[i]);
        }

        vector<int>dp1(nums1.size(), -1), dp2(nums2.size(), -1);
        return max(rob(nums1.size()-1, nums1, dp1), rob(nums2.size()-1, nums2, dp2));

    }
};