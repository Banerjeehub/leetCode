class Solution {
public:
    bool isPalindrome(int i, int j, string &s)
    {
        while(i <= j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void f(int idx, string &s, vector<string>&temp, vector<vector<string>>&ans)
    {
        if(idx == s.size())
        {
            ans.push_back(temp);
            return;
        }

        for(int i=idx; i<s.size(); i++)
        {
            if(isPalindrome(idx, i, s))
            {
                temp.push_back(s.substr(idx, i-idx+1));
                f(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<string>temp;
        vector<vector<string>>ans;
        f(0, s, temp, ans);
        return ans;
    }
};