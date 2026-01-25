class Solution {
public:
    int findLowestIdx(vector<int>&nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int lowestIdx = INT_MAX;
        int highestIdx = INT_MIN;

        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                lowestIdx = min(lowestIdx, mid);
                high = mid - 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return lowestIdx == INT_MAX ? -1 : lowestIdx;
    }
    int findLastIdx(vector<int>&nums, int target){
        int low = 0;
        int high = nums.size() - 1;
        int highestIdx = INT_MIN;

        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == target){
                highestIdx = max(highestIdx, mid);
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return highestIdx == INT_MIN ? -1 : highestIdx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        return {findLowestIdx(nums, target), findLastIdx(nums, target)};

    }
};