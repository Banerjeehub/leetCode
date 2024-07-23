class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (auto it : nums) {
            mpp[it]++;
        }

        vector<pair<int, int>> num;
        for (auto it : mpp) {
            num.push_back({it.second, it.first});
        }

        sort(num.begin(), num.end(), [](auto& a, auto& b) {
            if (a.first == b.first)
                return a.second > b.second; 
                                            
            return a.first < b.first;
        });

        vector<int> ans;
        for (auto it : num) {
            while (it.first--) {
                ans.push_back(it.second);
            }
        }
        return ans;
    }
};