class Solution {
public:
    void f(int open, int close, vector<string>&ans, string s)
    {
        if(open == 0 && close == 0)
        {
            ans.push_back(s);
            return;
        }

        if(open > 0)
        {
            f(open-1, close, ans, s+"(");
        }
        if(close > open) f(open , close-1, ans, s+")");
    }
    vector<string> generateParenthesis(int n) {
        int open = n;
        int close = n;
        vector<string>ans;
        string s="";
        f(open, close, ans, s);
        return ans;
    }
};