class Solution {
public:
    bool isValid(const string &s) {
        // Check if the segment is between 0 and 255
        if (s.size() > 3 || s.empty() || (s[0] == '0' && s.size() > 1) || stoi(s) > 255) {
            return false;
        }
        return true;
    }

    void backtrack(int start, string &s, vector<string> &current, vector<string> &result) {
        if (current.size() == 4) {
            // If we have 4 segments and we've used up all the string, we found a valid IP
            if (start == s.size()) {
                result.push_back(current[0] + "." + current[1] + "." + current[2] + "." + current[3]);
            }
            return;
        }

        // Try segments of length 1, 2, and 3
        for (int len = 1; len <= 3; len++) {
            if (start + len > s.size()) {
                break;
            }
            string segment = s.substr(start, len);
            if (isValid(segment)) {
                current.push_back(segment);
                backtrack(start + len, s, current, result);
                current.pop_back(); // Backtrack
            }
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> current;
        backtrack(0, s, current, result);
        return result;
    }
};