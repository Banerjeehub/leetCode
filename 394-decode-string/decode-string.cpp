class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> numStack;
        string currStr = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                numStack.push(num);
                st.push(currStr);
                num = 0;
                currStr = "";
            } else if (c == ']') {
                int repeatTimes = numStack.top();
                numStack.pop();
                string temp = currStr;
                for (int i = 1; i < repeatTimes; i++) {
                    currStr += temp;
                }
                currStr = st.top() + currStr;
                st.pop();
            } else {
                currStr += c;
            }
        }

        return currStr;
    }
};