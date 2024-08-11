class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        unordered_map<char, int>mpp;

        for(int i=0; i<3; i++)
        {
            mpp[s[i]]++;
        }
        if(mpp.size() == 3) count++;

        for(int i=3; i<s.size(); i++)
        {
            mpp[s[i]]++;
            mpp[s[i-3]]--;
            if(mpp[s[i-3]] == 0) mpp.erase(s[i-3]);

            if(mpp.size() == 3)
            {
                count++;
            }
        }

        return count;
    }
};