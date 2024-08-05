class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int mini = INT_MAX;
        vector<vector<int>>ans;
        for(int i=0; i<=n-2; i++)
        {
            if(abs(arr[i] - arr[i+1]) < mini)
            {
                mini = abs(arr[i] - arr[i+1]);
                ans.clear();
                ans.push_back({arr[i], arr[i+1]});
            }

            else if(abs(arr[i] - arr[i+1]) == mini)
            {
                ans.push_back({arr[i], arr[i+1]});
            }
        }

        return ans;
    }
};