class Solution {
public:
    bool isPossible(long long mid, int totalTrips,vector<int>& time)
    {
        long long ans = 0;
        for(auto it : time)
        {
            ans += (mid / it);
        }
        if(ans >= totalTrips)
        {
            return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long low = 1;
        long long high = (long long)*min_element(time.begin(), time.end()) * totalTrips;

        while(low < high)
        {
            long long mid = low + (high - low)/2;
            if(isPossible(mid, totalTrips, time))
            {
                high = mid;
            }
            else low = mid + 1;
        }

        return low;

        

    }
};