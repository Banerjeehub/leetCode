class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> count;

        for (int i = 0; i < target.size(); ++i) {
            count[target[i]]++;
            count[arr[i]]--;
        }

        for (auto it : count) {
            if (it.second != 0) return false;
        }

        return true;
    }
};