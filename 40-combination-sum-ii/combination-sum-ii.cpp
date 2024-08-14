class Solution {
private:
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
            if(i < idx && arr[idx] == arr[idx-1])  continue;
            temp.push_back(arr[idx]);
            f(idx+1, arr, target - arr[idx], temp, ans);
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