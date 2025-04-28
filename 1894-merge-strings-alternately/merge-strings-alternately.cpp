class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        string ans = "";
        int i = 0;
        int j = 0;
        int n = word1.size();
        int m = word2.size();

        while(i < n && j < m)
        {
            ans += word1[i++];
            ans += word2[j++];
        }
        if(i < n)
        {
            ans += word1.substr(i, n);
        }
        else ans += word2.substr(j, m);

        return ans;
    }
};