class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int, int> mpp;
        int count = 0;
        int n = nums.size();
        vector<int> ans;
        for (auto it : nums) {
            mpp[it]++;
        }
        vector<vector<int>> arr(n + 1);
        for (auto it : mpp) {
            arr[it.second].push_back(it.first);
        }

        for (int i = n; i >= 0 && count < k; i--) {
            for (auto it : arr[i]) {
                if (count < k) {
                    ans.push_back(it);
                    count++;
                } else
                    break;
            }
        }

        return ans;
    }
};