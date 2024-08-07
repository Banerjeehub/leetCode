class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        unordered_set<char>
            charSet;       // Set to store characters in the current window
        int start = 0;     // Start index of the window
        int maxLength = 0; // Maximum length of substring found

        for (int end = 0; end < s.length(); ++end) {
            // If the character is already in the set, remove characters from
            // the start
            while (charSet.find(s[end]) != charSet.end()) {
                charSet.erase(s[start]);
                ++start;
            }

            // Add the current character to the set
            charSet.insert(s[end]);
            // Update the maximum length
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};