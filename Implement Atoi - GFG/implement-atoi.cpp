//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        bool flag = false;
        int count = 0;
        
        for(int i=0; i<str.length();i++)
        {
            if(str[i] == '-' && i >0) return -1;
            if(!isdigit(str[i]))count++;
            if(count >1) return -1;
        }
        
        if(str[0] == '-') flag = true;
        int ans = 0;
        for(int i=0;i<str.length(); i++)
        {
            if(str[i] == '-')continue;
            if(isalpha(str[i])) return -1;
            
            int remain = (str[i] - '0') % 10;
            ans  = ans * 10 + remain;
        }
        
        if(flag) return ans * (-1);
        else return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends