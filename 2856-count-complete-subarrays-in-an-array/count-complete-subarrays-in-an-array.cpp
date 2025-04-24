class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        int left = 0, count = 0;

        for (int right = 0; right < n; ++right) {
            if (freq[nums[right]] == 0)
                k--;
            freq[nums[right]]++;

            while (k < 0) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    k++;
                left++;
            }

            count += (right - left + 1);
        }

        return count;
    }

    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> totalSet(nums.begin(), nums.end());
        int totalDistinct = totalSet.size();

        return atMostKDistinct(nums, totalDistinct) -
               atMostKDistinct(nums, totalDistinct - 1);
    }
};