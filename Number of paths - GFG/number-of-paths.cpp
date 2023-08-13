//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
long long  numberOfPaths(int m, int n)
{
    int N = m + n - 2;
    int R = n - 1;
    
    long long res = 1;
    
    for(int i=1; i<=R; i++)
    {
        res = res * (N-R+i)/i;
    }
    
    return res;
}

//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends