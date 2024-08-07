class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        string concatenated = goal + goal;
        return concatenated.find(s) != string::npos;
    }
};