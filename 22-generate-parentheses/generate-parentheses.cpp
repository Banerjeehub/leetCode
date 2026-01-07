class Solution {
public:
    void helper(int openCount, int closeCount, string temp,
                vector<string>& ans) {
        if (openCount == 0 && closeCount == 0) {
            ans.push_back(temp);
            return;
        }

        if (openCount > 0)
            helper(openCount - 1, closeCount, temp + '(', ans);
        if (closeCount > openCount) {
            helper(openCount, closeCount - 1, temp + ')', ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        helper(n, n, temp, ans);
        return ans;
    }
};