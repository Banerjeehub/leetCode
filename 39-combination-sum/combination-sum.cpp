class Solution {
public:
    void helper(int idx, int target, vector<int>& can, vector<int>& temp, vector<vector<int>>&ans){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(target < 0) return;
        if(idx == can.size()) return;

        temp.push_back(can[idx]);
        helper(idx, target-can[idx], can, temp, ans);
        temp.pop_back();
        helper(idx+1, target, can, temp, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0, target, candidates, temp, ans);
        return ans;
    }
};