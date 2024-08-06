class Solution {
private:
    void f(int idx, vector<int>& arr, int target, vector<int>& temp,
           vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (target < 0)
            return;

        for (int i = idx; i < arr.size(); i++) {
            if( i > idx && arr[i] == arr[i-1]) continue;
            temp.push_back(arr[i]);
            f(i + 1, arr, target - arr[i], temp, ans);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {

        vector<vector<int>> ans;
        vector<int> temp;
        sort(arr.begin(), arr.end());
        f(0, arr, target, temp, ans);
        return ans;
    }
};