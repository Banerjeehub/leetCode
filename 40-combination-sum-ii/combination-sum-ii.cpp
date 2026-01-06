class Solution {
public:
    void helper(int idx, vector<int>& temp, vector<int>& can, int target,
                vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (target < 0)
            return;
        if (idx == can.size()) {
            return;
        }

        // not take

        temp.push_back(can[idx]);
        helper(idx + 1, temp, can, target - can[idx], ans);
        temp.pop_back();
        while (idx + 1 < can.size() && can[idx] == can[idx + 1])
            idx++;
        helper(idx + 1, temp, can, target, ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        sort(can.begin(), can.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, temp, can, target, ans);
        return ans;
    }
};