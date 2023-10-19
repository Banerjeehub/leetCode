class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a, b;

        for(int i=0;i<s.size(); i++)
        {
            if(s[i] != '#')
            {
                a += s[i];
            }
            else if(s[i] == '#' && !a.empty())
            {
                a.pop_back();
            }
        }
        for(int i=0;i<t.size(); i++)
        {
            if(t[i] != '#')
            {
                b += t[i];
            }
            else if(t[i] == '#' && !b.empty())
            {
                b.pop_back();
            }
        }

        if(a == b) return true;
        return false;
    }
};