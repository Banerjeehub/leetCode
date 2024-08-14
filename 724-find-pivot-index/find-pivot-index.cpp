class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);  // Step 1
    int left_sum = 0;
    
    for (int i = 0; i < nums.size(); i++) {  // Step 2
        int right_sum = total_sum - left_sum - nums[i];  // Step 3
        
        if (left_sum == right_sum) {
            return i;  // Return the pivot index
        }
        
        left_sum += nums[i];  // Step 4
    }
    
    return -1;
    }
};