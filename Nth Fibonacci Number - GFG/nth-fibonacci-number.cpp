//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution {
  public:
  #define MOD  1000000007
    int solve(int n, vector<int>&dp)
    {
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        
        
        return dp[n] = (solve((n-1), dp) + solve((n-2), dp))%MOD;
    }
    int nthFibonacci(int n)
    {
        
        vector<int>dp(n+1, -1);
        n = n % MOD;
        return solve(n, dp) % MOD;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends