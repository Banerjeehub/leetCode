class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        double iniAvg = 0;
        for(int i=0; i<k; i++)
        {
            iniAvg += nums[i];
        }
        
        double maxAvg = iniAvg/k;
        
        for(int i=k; i<nums.size(); i++)
        {
            iniAvg += (nums[i] - nums[i-k]);
            maxAvg = max(iniAvg/k, maxAvg);
        }

        return maxAvg;

        
    }
};