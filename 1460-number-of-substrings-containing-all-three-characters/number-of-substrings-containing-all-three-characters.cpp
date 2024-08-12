class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> count;
        int left = 0;
        int result = 0;
        
        for (int right = 0; right < s.size(); ++right) {
            count[s[right]]++;
            
            while (count['a'] > 0 && count['b'] > 0 && count['c'] > 0) {
                result += s.size() - right;
                count[s[left]]--;
                left++;
            }
        }
        
        return result;
    }
};