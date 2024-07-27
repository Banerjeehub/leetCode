class Solution {
public:
    int findNext(vector<vector<int>>& events, int start, int toFind) {
        int low = start;
        int high = events.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (events[mid][0] >= toFind) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    long long f(int idx, int n, vector<vector<int>>& rides, vector<long long>& dp) {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];

        // Option 1: Skip the current ride
        long long notPick = f(idx + 1, n, rides, dp);

        // Option 2: Take the current ride
        int next = findNext(rides, idx + 1, rides[idx][1]);
        long long pick = rides[idx][1] - rides[idx][0] + rides[idx][2];
        if (next != -1) {
            pick += f(next, n, rides, dp);
        }

        // Memoize the result and return the maximum of both options
        return dp[idx] = max(pick, notPick);
    }

    long long maxTaxiEarnings(int N, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        int n = rides.size();
        vector<long long> dp(n, -1);
        return f(0, n, rides, dp);
    }
};
