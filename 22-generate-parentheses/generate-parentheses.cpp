class Solution {
public:
    void f(int open, int close, string s, vector<string>&ans)
    {
        if(open == 0 && close == 0)
        {
            ans.push_back(s);
            return;
        }

        if(open > 0)
        {
            f(open-1, close, s+'(', ans);
        }
        if(open < close)
        {
            f(open, close-1, s+')', ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int open = n;
        int close = n;
         f(open, close, "", ans);
         return ans;
    }
};