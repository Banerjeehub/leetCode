//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    
    int f(int index, int *nums, vector<int>&dp)
    {
        if(index == 0) return nums[index];
        if(index < 0) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int pick = nums[index] + f(index-2, nums, dp);
        int notPick = 0 + f(index-1, nums, dp);
        
        return dp[index] = max(pick, notPick);
    }
    int FindMaxSum(int arr[], int n)
    {
        int size = n-1;
        vector<int>dp(size+1, -1);
        return f(size, arr, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends