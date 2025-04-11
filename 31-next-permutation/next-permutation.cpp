class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int pivotIdx = -1;
        int n = nums.size();

        for(int i=n-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                pivotIdx = i;
                break;
            }
        }

        if(pivotIdx == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i=n-1; i>=0; i--)
        {
            if(nums[pivotIdx] < nums[i])
            {
                swap(nums[pivotIdx], nums[i]);
                break;
            }
        }

        reverse(nums.begin()+pivotIdx+1, nums.end());
        return;
    }
};