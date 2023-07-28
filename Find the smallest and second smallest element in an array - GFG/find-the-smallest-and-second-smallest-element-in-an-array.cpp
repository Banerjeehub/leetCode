//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> minAnd2ndMin(int a[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];

        for (int i = 0; i < n; i++) 
            cin >> a[i];

        vector<int> ans = minAnd2ndMin(a, n);
        if (ans[0] == -1)
            cout << -1 << endl;
        else 
            cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
// } Driver Code Ends


vector<int> minAnd2ndMin(int a[], int n) {
    
    int ans1 = INT_MAX;
    int ans2 = INT_MAX;
    
    for(int i=0;i<n;i++)
    {
        ans1 = min(ans1, a[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        if(a[i] != ans1)
        {
            ans2 = min(ans2, a[i]);
        }
    }
    
    if(ans1 != INT_MAX && ans2!=INT_MAX) return {ans1, ans2};
    else return {-1};
}