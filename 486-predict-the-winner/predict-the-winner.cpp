class Solution {
public:
    int check(vector<int>& nums, int start, int end, vector<vector<int>>& dp) {
        if (start == end)
            return nums[start];
        if (dp[start][end] != -1)
            return dp[start][end];
        int a = nums[start] - check(nums, start + 1, end, dp);
        int b = nums[end] - check(nums, start, end - 1, dp);
        return dp[start][end] = max(a, b);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return check(nums, 0, nums.size() - 1, dp) >= 0;
    }
};