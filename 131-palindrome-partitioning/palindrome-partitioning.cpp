class Solution {
public:
    bool isPalindrome(int i, int j, string s)
    {
        while(i <= j)
        {
            if(s[i] != s[j]) return false;
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
    void f(int index, int n, string s, vector<vector<string>>&ans, vector<string>&res)
    {
        if(index == n){
            ans.push_back(res);
            return;
        }

        for(int i=index; i<n; i++)
        {
            if(isPalindrome(index, i, s))
            {
                res.push_back(s.substr(index, i-index+1));
                f(i+1, n, s, ans, res);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>>ans;
        vector<string>res;
        f(0, n, s, ans, res);
        return ans;
    }
};