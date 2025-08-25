#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        const long long INF = (1LL<<62);

        int n = robots.size(), m = walls.size();
        // Pair robot position with distance and sort by position
        vector<pair<long long,long long>> R(n);
        for (int i = 0; i < n; ++i) R[i] = {robots[i], distance[i]};
        sort(R.begin(), R.end());
        sort(walls.begin(), walls.end());

        // Helper to count walls in [L, R] inclusive using binary search
        auto cnt_in = [&](long long L, long long R)->int{
            if (L > R) return 0;
            auto it1 = lower_bound(walls.begin(), walls.end(), L);
            auto it2 = upper_bound(walls.begin(), walls.end(), R);
            return (int)(it2 - it1);
        };

        // Count walls exactly at robot positions (unique positions)
        int at_robot = 0;
        for (int i = 0; i < n; ++i) {
            if (binary_search(walls.begin(), walls.end(), (int)R[i].first))
                at_robot++;
        }

        // Exterior gaps (exclude the wall at robot position itself)
        long long p0 = R.front().first, d0 = R.front().second;
        int left_ext = cnt_in(p0 - d0, p0 - 1);   // first robot shoots left

        long long pn = R.back().first, dn = R.back().second;
        int right_ext = cnt_in(pn + 1, pn + dn);  // last robot shoots right

        // For internal gaps between robots i and i+1
        vector<int> onlyRight(n-1, 0);  // a[i] : robot i shoots right
        vector<int> onlyLeft(n-1, 0);   // b[i] : robot i+1 shoots left
        vector<int> both(n-1, 0);       // c[i] : both shoot towards gap (union)

        for (int i = 0; i + 1 < n; ++i) {
            long long x  = R[i].first,  di = R[i].second;
            long long y  = R[i+1].first, dj = R[i+1].second;

            // walls strictly between robots (exclude x and y to avoid double count)
            long long gapL = x + 1, gapR = y - 1;
            if (gapL > gapR) { onlyRight[i]=onlyLeft[i]=both[i]=0; continue; }

            long long rReach = min(x + di, y - 1);           // i shoots right
            long long lReach = max(y - dj, x + 1);           // i+1 shoots left

            int A = cnt_in(x + 1, rReach);
            int B = cnt_in(lReach, y - 1);

            int overlap = cnt_in(max(lReach, x + 1), min(rReach, y - 1));
            onlyRight[i] = A;
            onlyLeft[i]  = B;
            both[i]      = A + B - overlap;
        }

        // DP
        const int NEG = -1e9;
        vector<array<int,2>> dp(n, {NEG, NEG});
        // i = 0
        dp[0][0] = left_ext;  // first robot shoots left -> covers left exterior
        dp[0][1] = 0;         // first robot shoots right -> nothing yet (gap handled with i=1)

        for (int i = 1; i < n; ++i) {
            // current shoots left
            dp[i][0] = max(dp[i-1][0] + onlyLeft[i-1],   // (L,L)
                           dp[i-1][1] + both[i-1]);      // (R,L)
            // current shoots right
            dp[i][1] = max(dp[i-1][0] + 0,               // (L,R)
                           dp[i-1][1] + onlyRight[i-1]); // (R,R)
        }

        // add right exterior if last shoots right
        int best = max(dp.back()[0], dp.back()[1] + right_ext);

        // add walls that are exactly at robot positions (always destroyed)
        return best + at_robot;
    }
};