class Solution {
public:
// 2 1 5 4 3 0 0
// 2 3 5 4 1 0 0
// 2 3 0 0 1 4 5

    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;

        for(int i = n-2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                idx = i;
                break;
            }
        }
        if(idx == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i=n-1; i>=0; i--)
        {
            if(nums[idx] < nums[i])
            {
                swap(nums[idx], nums[i]);
                break;
            }
        }

        reverse(nums.begin()+idx+1, nums.end());
        return;




    }
};