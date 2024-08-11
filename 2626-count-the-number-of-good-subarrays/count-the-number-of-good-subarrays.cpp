class Solution {
public:
long long countGood(vector<int>& nums, int k) {
        long long count = 0;
        long long pairs = 0;
        unordered_map<int, int> freqMap;
        int left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            int num = nums[right];
            // Update the number of pairs with the current element
            if (freqMap[num] > 0) {
                pairs += freqMap[num];
            }
            freqMap[num]++;

            // While the number of pairs is at least k, count the number of subarrays
            while (pairs >= k) {
                count += (nums.size() - right); // Count subarrays from left to the end
                int leftNum = nums[left];
                // Update the number of pairs with the element being removed
                if (freqMap[leftNum] > 1) {
                    pairs -= (freqMap[leftNum] - 1);
                }
                freqMap[leftNum]--;
                left++;
            }
        }

        return count;
    }
};