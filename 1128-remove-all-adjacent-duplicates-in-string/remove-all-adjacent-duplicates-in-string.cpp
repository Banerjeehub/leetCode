class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char>st;

        for(auto it : s)
        {
            if(!st.empty() && st.top() == it) st.pop();
            else st.push(it);
        }

        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};