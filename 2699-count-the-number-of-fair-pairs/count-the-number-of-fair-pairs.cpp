class Solution {
public:
    // Returns how many elements nums[j] (j > i) make nums[i] + nums[j] lie in [lower, upper]
    int bs(int i, vector<int>& arr, int lower, int upper)
    {
        int n = arr.size();
        int low = i + 1;
        int high = n - 1;
        int left = n, right = i;

        // Find first index j such that arr[i] + arr[j] >= lower
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(arr[i] + arr[mid] >= lower)
            {
                left = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }

        low = i + 1;
        high = n - 1;

        // Find last index j such that arr[i] + arr[j] <= upper
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(arr[i] + arr[mid] <= upper)
            {
                right = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }

        if(left <= right)
            return right - left + 1;
        return 0;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long count = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            count += bs(i, nums, lower, upper);
        }

        return count;
    }
};