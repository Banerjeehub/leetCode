
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> mp;
        int minm = INT_MAX; // Initialize minm to a large value
        int count;
        int n = cards.size();
        

        for (int i = 0; i < n; i++) {
            if (mp.count(cards[i])) {
                count = i - mp[cards[i]] + 1;
                minm = min(minm, count);
            }
            mp[cards[i]] = i;
        }
        if (minm == INT_MAX) { // No matching cards found
            return -1;
        }
        return minm;
    }
};