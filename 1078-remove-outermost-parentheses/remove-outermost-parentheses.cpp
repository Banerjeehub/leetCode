class Solution {
public:
    string removeOuterParentheses(string s) {
        
        int openCount = 0;
        string result = "";

        for( char it : s)
        {
            if(it == '(')
            {
                if(openCount > 0) result += it;
                openCount++;
            }
            else
            {
                openCount--;
                if(openCount > 0) result += it;
            }
        }

        return result;
    }
};