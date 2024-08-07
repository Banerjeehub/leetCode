class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int start = 0;
        unordered_set<char>st;
        int maxLen = 0;

        for(int end=0; end<s.length(); end++)
        {
            while(st.find(s[end]) != st.end())
            {
                st.erase(s[start]);
                start++;
            }
            st.insert(s[end]);
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};