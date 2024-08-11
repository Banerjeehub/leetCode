class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < k) {
            return 0;
        }

        unordered_map<int, int> freqMap;
        long long sum = 0, maxSum = 0;

        // Initialize the first window
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            freqMap[nums[i]]++;
        }

        if (freqMap.size() == k) {
            maxSum = sum;
        }

        // Slide the window
        for (int i = k; i < nums.size(); i++) {
            // Remove the element that's sliding out of the window
            sum -= nums[i - k];
            freqMap[nums[i - k]]--;
            if (freqMap[nums[i - k]] == 0) {
                freqMap.erase(nums[i - k]);
            }

            // Add the new element
            sum += nums[i];
            freqMap[nums[i]]++;

            // Check if this window has exactly k distinct elements
            if (freqMap.size() == k) {
                maxSum = max(maxSum, sum);
            }
        }

        return maxSum;
    }
};