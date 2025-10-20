class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mpp;
        vector<vector<string>>ans;
        for(auto it : strs)
        {
            int alpha[26] = {0};
            for(auto i : it) alpha[i - 'a']++;

            string key; 
            key.reserve(26 * 2);
            for(int i=0; i<26; i++)
            {
                key += "#";
                key += to_string(alpha[i]);
            }
            mpp[key].push_back(it);

        }

        for(auto it : mpp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};