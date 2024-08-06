class Solution {
public:
    int binarySearch(int low, int high, vector<int>& nums, int target) {

        if (low > high)
            return -1;

        int mid = (low + high) / 2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target) {
            return binarySearch(low, mid - 1, nums, target);
        } else
            return binarySearch(mid + 1, high, nums, target);
    }
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        int ans = binarySearch(low, high, nums, target);
        return ans;
    }
};