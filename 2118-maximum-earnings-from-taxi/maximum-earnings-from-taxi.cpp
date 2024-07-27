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

    long long maxTaxiEarnings(int N, vector<vector<int>>& rides) {
        sort(rides.begin(), rides.end());
        int n = rides.size();
        vector<long long> dp(n + 1, 0); // DP array initialized with 0, size n+1 for easier boundary management

        // Iterate from the last ride to the first ride
        for (int idx = n - 1; idx >= 0; --idx) {
            // Option 1: Skip the current ride
            long long notPick = dp[idx + 1];

            // Option 2: Take the current ride
            int next = findNext(rides, idx + 1, rides[idx][1]);
            long long pick = rides[idx][1] - rides[idx][0] + rides[idx][2];
            if (next != -1) {
                pick += dp[next];
            }

            // Store the maximum of both options
            dp[idx] = max(pick, notPick);
        }

        return dp[0]; // The result is the maximum earnings starting from the first ride
    }
};