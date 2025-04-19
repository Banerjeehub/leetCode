class Solution {
public:
    // Returns how many elements in nums[j] where j > i such that
    // lower - nums[i] <= nums[j] <= upper - nums[i]
    int countInRange(int i, vector<int>& arr, int lower, int upper) {
        int n = arr.size();
        int low = i + 1, high = n - 1;

        // Find first index j such that arr[j] >= lower
        int left = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= lower) {
                left = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        low = i + 1, high = n - 1;
        int right = i;
        // Find last index j such that arr[j] <= upper
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= upper) {
                right = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (left <= right)
            return right - left + 1;
        else
            return 0;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end()); // sorting can stay, it's not STL-specific logic
        long long count = 0;

        for (int i = 0; i < nums.size(); i++) {
            int newLower = lower - nums[i];
            int newUpper = upper - nums[i];

            count += countInRange(i, nums, newLower, newUpper);
        }

        return count;
    }
};