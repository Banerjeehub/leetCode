//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int chkDigit(int num)
        {
            if(num == 0) return 1;
            int count = 0;
            while(num > 0)
            {
                int remain = num % 10;
                num = num / 10;
                count++;
            }
            return count;
        }
        int isValid(string s) {
            int ans = 0;
            int count = 0;
            int dotCount = 0;
            for(int i=0; i<s.length(); i++)
            {
                
                if(s[i] != '.')
                {   if(isalpha(s[i])) return 0;
                    count++;
                    int remain = (s[i]-'0') % 10;
                    ans = ans * 10 + remain;
                }
                if(s[i] == '.')
                {
                    dotCount++;
                    int count1 = chkDigit(ans);
                     
                    if(ans > 255 || s[i+1] == '.'|| count!= count1 ) return 0;
                    else 
                    {
                        ans = 0;
                        count = 0;
                    }
                }
            }
            //cout<<count<<endl;
            int count1 = chkDigit(ans);
            if(count != count1 || dotCount < 3 || dotCount > 3) return 0;
            else return 1;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends