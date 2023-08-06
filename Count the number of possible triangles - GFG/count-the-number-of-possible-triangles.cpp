//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.
int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        sort(arr,arr+n);
        int ans = 0;
        for(int i=n-1;i>0;i--){
            int lo = 0,hi = i-1;
            while(lo<hi){
                if(arr[i]>=arr[lo]+arr[hi]){
                    lo++;
                }
                else{
                    ans += hi-lo;
                    hi--;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}
// } Driver Code Ends