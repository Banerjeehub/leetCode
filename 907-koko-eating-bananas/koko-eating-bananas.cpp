class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(low <= high){
            int k = (low + high) / 2;
            long long hour_needed = 0;
            for(auto it : piles){
                hour_needed += (it / k);
                if(it % k) hour_needed++;
            }
            if(hour_needed <= h){
                high = k - 1;
                ans = k;
            }
            else low = k + 1;
        }

        return ans;
    }
};