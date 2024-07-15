class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        int t1 = text1.size();
        int t2 = text2.size();

        vector<int>prev(t2+1, 0), curr(t2+1, 0);

        for(int i=1; i<=t1; i++)
        {
            for(int j=1; j<=t2; j++)
            {
                if(text1[i-1] == text2[j-1])
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
};