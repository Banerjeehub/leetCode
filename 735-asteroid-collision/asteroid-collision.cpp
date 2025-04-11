class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {

        // smaller one will explode (if moving in the opposite direction)
        // same direction will never meet

        stack<int> st;
        for (int i = 0; i < as.size(); i++) {
            if (st.empty() || as[i] > 0) {
                st.push(as[i]);
            } else {
                while (!st.empty() && st.top() > 0 && abs(as[i]) > st.top()) {
                    st.pop();
                }
                if (!st.empty() && st.top() == abs(as[i])) {
                    st.pop();
                } else {
                    if(st.empty() || st.top() < 0) st.push(as[i]);
                }
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};