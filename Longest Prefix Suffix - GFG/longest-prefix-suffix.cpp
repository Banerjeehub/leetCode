//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    int ans = INT_MIN;
	    
	    int n = s.length();
	    vector<int>lps(n);
	    lps[0] = 0;
	    int i(0),j(1);
	    
	    while(j<n)
	    {
	        if(s[i] == s[j])
	        {
	            lps[j++] = ++i;
	        }
	        else if(i) i = lps[i-1];
	        else lps[j++] = 0;
	    }
    return lps[s.size()-1];
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends