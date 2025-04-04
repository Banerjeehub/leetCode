#include <iostream>
#include <vector>
#include <numeric> // for accumulate
using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = (long long)*min_element(time.begin(), time.end()) * totalTrips;

        auto trips_in_time = [&](long long t) {
            long long trips = 0;
            for (int t_i : time) {
                trips += t / t_i;
                if (trips >= totalTrips) break; // early exit if already enough
            }
            return trips;
        };

        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (trips_in_time(mid) >= totalTrips) {
                high = mid; // try smaller time
            } else {
                low = mid + 1; // need more time
            }
        }

        return low;
    }
};