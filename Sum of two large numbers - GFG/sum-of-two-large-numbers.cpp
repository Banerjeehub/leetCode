//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string X, string Y) {
        int i = X.length()-1;
        int j = Y.length()-1;
        
        string ans = "";
        
        int carry = 0;
        while(i >= 0 || j >= 0 || carry != 0)
        {
            int num1 = i >= 0 ? X[i--]-'0' : 0;
            int num2 = j >= 0 ? Y[j--]-'0' : 0;
            
            int sum = num1 + num2 + carry;
            int remain = sum % 10;
            ans = to_string(remain) + ans;
            carry = sum / 10;
        }
        while(ans[0] == '0')ans.erase(ans.begin());
        if(ans.empty()) return "0";
        else return ans;
        
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends