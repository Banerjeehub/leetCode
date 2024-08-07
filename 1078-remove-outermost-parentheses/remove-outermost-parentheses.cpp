class Solution {
public:
    string removeOuterParentheses(string S) {
        string result;
        int openCount = 0;

        for (char c : S) {
            if (c == '(') {
                if (openCount > 0) {
                    result += c;  // Only add '(' if it is not an outermost one
                }
                openCount++;
            } else {
                openCount--;
                if (openCount > 0) {
                    result += c;  // Only add ')' if it is not an outermost one
                }
            }
        }

        return result;
    }
};