class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int, int>> num;
        unordered_map<int, int> mpp;
        auto cmp = [](auto& a, auto& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        };
        for (auto it : nums) {
            mpp[it]++;
        }

        for (auto it : mpp) {
            num.push_back({it.second, it.first});
        }

        sort(num.begin(), num.end(), cmp);

        vector<int> ans;
        for (auto it : num) {
            while (it.first--) {
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};