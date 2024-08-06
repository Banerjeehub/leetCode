class Solution {
public:
    void f(int i, vector<int>&arr, int target, vector<int>&temp, vector<vector<int>>&ans)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(target < 0) return;

        for(int idx=i; idx<arr.size(); idx++)
        {
            temp.push_back(arr[idx]);
            f(idx, arr, target - arr[idx], temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(0, arr, target, temp, ans);
        return ans;

    }
};