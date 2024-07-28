class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1), hash(n);
        int maxi = 1;
        int lastIdx = 0;
        for(int i=0; i<n; i++)
        {
            hash[i] = i;
            for(int j=0; j<i; j++)
            {
                if(nums[i] > nums[j] && (1+dp[j] > dp[i]))
                {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;

                }
                if(maxi < dp[i])
                {
                    maxi = dp[i];
                    lastIdx = i;
                }
            }
        }

        vector<int>li;
        li.push_back(nums[lastIdx]);
        while(hash[lastIdx] != lastIdx)
        {
            lastIdx = hash[lastIdx];
            li.push_back(nums[lastIdx]);
        }

        reverse(li.begin(), li.end());

        for(auto it : li) cout << it << " ";
        cout << endl;



        return maxi;
    }
};