class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;

        for (int i = 0; i < n; ++i) {
            int minVal = nums[i];
            int maxVal = nums[i];
            for (int j = i; j < n; ++j) {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);
                totalSum += (maxVal - minVal);
            }
        }

        return totalSum;
    }
};