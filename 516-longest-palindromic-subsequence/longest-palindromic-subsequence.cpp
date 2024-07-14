class Solution {
private:
    int lcs(string s1, string s2)
    {
        int t1 = s1.size();
        int t2 = s2.size();

        vector<int>prev(t2+1, 0), curr(t2+1, 0);

        for(int i=1; i<=t1; i++)
        {
            for(int j=1; j<=t2; j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    curr[j] = 1 + prev[j-1];
                }
                else
                {
                    curr[j] = max(curr[j-1], prev[j]);
                }
            }
            swap(prev, curr);
        }

        return prev[t2];
    }
public:
    int longestPalindromeSubseq(string s1) {
        
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return lcs(s1, s2);
    }
};