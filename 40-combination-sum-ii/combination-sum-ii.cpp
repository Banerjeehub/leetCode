class Solution {
public:
    void f(int idx, int target, vector<int>&nums, vector<int>&temp, vector<vector<int>>&ans)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(target < 0) return;

        for(int i=idx; i<nums.size(); i++)
        {
            if(idx < i && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            f(i+1, target - nums[i],nums,  temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        f(0, target, candidates, temp, ans);
        return ans;

    }
};