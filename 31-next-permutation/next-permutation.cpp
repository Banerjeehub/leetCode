class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the largest index `i` such that `nums[i] < nums[i + 1]`
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If no such index exists, the permutation is the last
        // permutation
        if (i >= 0) {
            // Step 3: Find the largest index `j` such that `nums[j] > nums[i]`
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            // Step 4: Swap the values of `nums[i]` and `nums[j]`
            swap(nums[i], nums[j]);
        }

        // Step 5: Reverse the subarray from `i + 1` to the end
        reverse(nums.begin() + i + 1, nums.end());
        
    }
};