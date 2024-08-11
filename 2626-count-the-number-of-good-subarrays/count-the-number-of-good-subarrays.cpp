class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        long long count = 0;
        long long pair = 0;
        unordered_map<int, int>mpp;

        int left = 0;
        for(int right = 0; right < nums.size(); right++)
        {
            int num = nums[right];
            if(mpp[num] > 0)
            {
                pair += mpp[num];
            }
            mpp[num]++;

            while(pair >= k)
            {
                count += nums.size() - right;
                int leftNum = nums[left];
                if(mpp[leftNum] > 1)
                {
                    pair -= (mpp[leftNum] - 1);
                }
                mpp[leftNum]--;
                left++;
            }
        }

        return count;
    }
};