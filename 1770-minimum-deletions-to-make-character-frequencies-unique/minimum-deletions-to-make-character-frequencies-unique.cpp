class Solution {
public:
    int minDeletions(string s) {
        
        vector<int>freq(26, 0);
        for(int i=0; i<s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }
        sort(freq.begin(), freq.end());
        int count = 0;

        for(int i=24; i>=0; i--)
        {
            if(freq[i] == 0) break;

            if(freq[i] >= freq[i+1])
            {
                int prev = freq[i];
                freq[i] = max(0, freq[i+1] - 1);
                count += prev - freq[i];
            }
        }

        return count;
    }
};