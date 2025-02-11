class Solution {
public:
    string removeOccurrences(string s, string part) {

        string res;
        stack<char> st;

        for (auto c : s) {
            st.push(c);

            if (st.size() >= part.size()) {
                string temp = "";
                for (int i = 0; i < part.size(); i++) {
                    temp = st.top() + temp;
                    st.pop();
                }

                if (temp != part) {
                    for (auto ch : temp) {
                        st.push(ch);
                    }
                }
            }
        }

        while (!st.empty()) {
            res = st.top() + res;
            st.pop();
        }

        return res;
    }
};