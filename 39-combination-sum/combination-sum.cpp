class Solution {
public:
    void backtrack(int index, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& results) {
        if (target == 0) {
            results.push_back(current);
            return;
        }
        if (target < 0) return;

        for (int i = index; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            backtrack(i, target - candidates[i], candidates, current, results);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        vector<int> current;
        backtrack(0, target, candidates, current, results);
        return results;
    }
};