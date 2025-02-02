class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int ans = INT_MAX;
        int start = 0;
        int end = 0;
        int sum = 0;

        for(end = 0; end < nums.size(); end++)
        {
            sum += nums[end];
            while(sum >= target)
            {
                ans = min(ans, end-start+1);
                sum -= nums[start++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};