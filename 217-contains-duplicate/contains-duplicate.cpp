class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i=0,j=i+1; i<=nums.size()-2, j<=nums.size()-1; i++,j++)
        {
            if(nums[i] == nums[j]) return true;
        }
        return false;
    }
};