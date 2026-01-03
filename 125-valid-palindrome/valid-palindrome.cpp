class Solution {
public:
    string helper(int i, int j, string &san){
        if(i >= j) return san;

        swap(san[i++], san[j--]);
        return helper(i, j, san);
    }
    bool isPalindrome(string s) {
        string san = "";
        for(auto it : s){
            if(isalnum(it))
            {
                san.push_back(tolower(it));
            }
        }
        string copyOfSan = san;
        string rev = helper(0, san.size() - 1, copyOfSan);
        return san == rev;
    }
};