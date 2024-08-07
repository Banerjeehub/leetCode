class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int>st(nums.begin(), nums.end());
        int maxCount = 0;
        for(auto it : st)
        {
            if(st.find(it-1) == st.end())
            {
                int num = it;
                int count = 1;

                while(st.find(num+1) != st.end())
                {
                    num = num+1;
                    count++;
                }
                maxCount = max(maxCount, count);
            }
        }

        return maxCount;
    }
};