class Solution {
public:
    string longestPalindrome(string s) {
        
        string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    int n = s.size();
    int maxLength = 0, endIndex = 0;
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i - 1] == rev_s[j - 1]) {
                curr[j] = prev[j - 1] + 1;
                // Check if the substring is palindromic
                int startInOriginal = i - curr[j];
                int endInReversed = n - j;
                if (startInOriginal == endInReversed) {
                    if (curr[j] > maxLength) {
                        maxLength = curr[j];
                        endIndex = i;
                    }
                }
            } else {
                curr[j] = 0;
            }
        }
        swap(prev, curr);
    }
    
    return s.substr(endIndex - maxLength, maxLength);
    }
};