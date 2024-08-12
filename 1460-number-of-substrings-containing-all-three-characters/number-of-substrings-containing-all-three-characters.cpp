class Solution {
public:
    int numberOfSubstrings(string s) {
        
        unordered_map<char, int>mpp;
        int left = 0;
        int count = 0;

        for(int i=0; i<s.size(); i++)
        {
            mpp[s[i]]++;
            while(mpp['a'] > 0 && mpp['b'] > 0 && mpp['c'] > 0)
            {
                count += s.size() - i;
                mpp[s[left]]--;
                left++;
            }

        }

        return count;
    }
};