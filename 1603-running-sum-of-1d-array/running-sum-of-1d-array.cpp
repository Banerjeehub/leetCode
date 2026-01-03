class Solution {
public:
    vector<int>helper(int idx, vector<int>&nums){
        if(idx == nums.size()) return nums;

        nums[idx] += nums[idx-1];
        return helper(idx+1, nums);
    }
    vector<int> runningSum(vector<int>& nums) {
        int idx = 1;
        return helper(idx, nums);
    }
};