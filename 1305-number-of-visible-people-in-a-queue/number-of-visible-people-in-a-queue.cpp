class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
    int n = heights.size();
    vector<int> ans(n, 0);
    stack<int> st; // stack stores indices or heights

    for (int i = n - 1; i >= 0; --i) {
        int count = 0;

        // Pop all shorter people (visible)
        while (!st.empty() && heights[i] > st.top()) {
            st.pop();
            count++;
        }

        // If someone taller or equal is still there, they can also be seen
        if (!st.empty()) count++;

        ans[i] = count;
        st.push(heights[i]);
    }

    return ans;
}
};