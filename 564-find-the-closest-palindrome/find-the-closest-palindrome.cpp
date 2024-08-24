class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        set<string>candidates;

        candidates.insert(string(len-1, '9'));
        candidates.insert("1" + string(len-1, '0') + "1");

        long prefixNum = 0;
        try{
            prefixNum = stol(n.substr(0, (len+1)/2));
        }catch(const invalid_argument& e)
        {
            return "";
        }

        for(int i=-1; i<=1; i++)
        {
            string prefix = to_string(prefixNum + i);
            string candidate;

            if(len % 2 == 0)
            {
                candidate = prefix + string(prefix.rbegin(), prefix.rend());
            }
            else candidate = prefix + string(prefix.rbegin()+1, prefix.rend());

            candidates.insert(candidate);
        }

        candidates.erase(n);


        string ans;
        long min_diff = LONG_MAX;

        for(auto it : candidates)
        {
            long diff = 0;
            try{
                diff = abs(stol(n) - stol(it));
            }
            catch(const invalid_argument& e)
            {
                continue;
            }


            if(diff < min_diff || (diff == min_diff && stol(it) < stol(ans)))
            {
                ans = it;
                min_diff = diff;
            }
        }

        return ans;
    }
};