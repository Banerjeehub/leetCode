//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
int findLastOccurence(string A,string B){
        //We can reverse the question as first ocuurrence in in reversed A, B
       reverse(A.begin(), A.end()); reverse(B.begin(), B.end());
        
        int n = A.size(), m = B.size();
        
        //lps longest prefix-suffix
        vector<int>lps(m);
        int k = 0, i = 1;
        while(i<m){
            if(B[i]==B[k]) lps[i++] = ++k;
            else if(k) k = lps[k-1];
            else lps[i++] = 0;
        }
        
        k = 0, i = 0;
        //using kmp algorithm finding first ocuurence
        while(i<n){
            if(A[i] == B[k]) {  k++, i++; }
            else if(k) k = lps[k-1];
            else i++;
            if(k==m) return n-i+1;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A>>B;
        Solution ob;
        cout<<ob.findLastOccurence(A,B)<<"\n";
        
    } 
    return 0; 
}
// } Driver Code Ends