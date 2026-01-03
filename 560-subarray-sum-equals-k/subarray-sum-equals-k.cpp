class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> count;
        int sum = 0;
        count[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (count.find(sum - k) != count.end()) {
                ans += count[sum-k];
            }

            count[sum]++;
        }

        return ans;
    }
};