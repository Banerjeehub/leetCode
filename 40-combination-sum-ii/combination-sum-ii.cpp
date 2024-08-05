class Solution {
public:
    void f(int i, vector<int>& temp, vector<int>& arr, vector<vector<int>>& ans, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (target < 0) return;

        for (int idx = i; idx < arr.size(); idx++) {
            // Skip duplicates
            if (idx > i && arr[idx] == arr[idx - 1]) continue;
            temp.push_back(arr[idx]);
            f(idx + 1, temp, arr, ans, target - arr[idx]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        // Sort the candidates to handle duplicates
        sort(candidates.begin(), candidates.end());

        f(0, temp, candidates, ans, target);
        return ans;
    }
};