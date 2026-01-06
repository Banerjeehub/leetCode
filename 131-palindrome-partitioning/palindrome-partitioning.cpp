class Solution {
public:
    bool isPalindrome(string s){
        int i = 0;
        int j = s.length() - 1;

        while(i <= j){
            if(s[i] != s[j]) return false;
            else {
                i++;
                j--;
            }
        }

        return true;
    }
    void helper(int idx, string &s, vector<string>&temp, vector<vector<string>>&ans){
        if(idx == s.length()){
            ans.push_back(temp);
            return;
        }

        for(int i=idx; i<s.length(); i++)
        {
            string ss = s.substr(idx, i - idx + 1);
            if(isPalindrome(ss)){
                temp.push_back(ss);
                helper(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        helper(0, s, temp, ans);
        return ans;
        
    }
};