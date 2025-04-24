class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
    int n = nums.size();
    unordered_set<int> totalSet(nums.begin(), nums.end());
    int totalDistinct = totalSet.size();

    int count = 0;

    for (int start = 0; start < n; ++start) {
        unordered_map<int, int> freq;
        int distinct = 0;

        for (int end = start; end < n; ++end) {
            if (freq[nums[end]] == 0)
                distinct++;
            freq[nums[end]]++;

            if (distinct == totalDistinct)
                count++;
        }
    }

    return count;
}
};