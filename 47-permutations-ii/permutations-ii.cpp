class Solution {
public:
    void helper(int idx, vector<int>& nums, vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> st;
        for (int i = idx; i < nums.size(); i++) {
            if(st.count(nums[i])) continue;
            st.insert(nums[i]);
            swap(nums[i], nums[idx]);
            helper(idx + 1, nums, ans);
            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        helper(0, nums, ans);
        return ans;
    }
};