class Solution {
public:
    char findTheDifference(string s, string t) {
        
        if(s.size() == 0) return t[0];
        char ans;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i=0; i<t.size(); i++)
        {
            if(s[i] != t[i])
            {
                ans = t[i];
                break;
            }
        }

        return ans;

    }
};