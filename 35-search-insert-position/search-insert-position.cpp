class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // The main target is to find the lowest possible pos
        // where we can put the target
        // now as its sorted in an ascending order
        // we can check if the current mid index is greater or equal to the target
        // because if the current mid is greater or equal now then all the elements in the right has the possibility of being eligible for the index
        // as if we are looking for the lowest possible index we will go to the left and discard the right.


        int low = 0;
        int high = nums.size() - 1;

        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] >= target){
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return low;
    }
};