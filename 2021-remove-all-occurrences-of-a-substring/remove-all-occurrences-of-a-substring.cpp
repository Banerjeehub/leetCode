class Solution {
public:
    string removeOccurrences(string s, string part) {

         string result;
    stack<char> st;
    
    for (char c : s) {
        st.push(c);
        
        // Check if the top of the stack forms `part`
        if (st.size() >= part.size()) {
            string temp;
            for (int i = part.size() - 1; i >= 0; --i) {
                temp = st.top() + temp;
                st.pop();
            }
            
            // If temp is not equal to `part`, push back the characters
            if (temp != part) {
                for (char ch : temp) {
                    st.push(ch);
                }
            }
        }
    }
    
    // Construct the final string
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }
    
    return result;
    }
};