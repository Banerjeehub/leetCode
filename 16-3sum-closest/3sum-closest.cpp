class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closest_sum = INT_MAX/2;
        for(int i=0; i<n-2; i++)
        {
            int j = i + 1;
            int k = n - 1;

            while(j < k)
            {
                int currSum = nums[i] + nums[j] + nums[k];
                if(abs(currSum - target) < abs(closest_sum - target))
                {
                    closest_sum = currSum;
                }
                if(currSum > target)
                {
                    k--;
                }
                else if(currSum < target) j++;
                else return currSum;
            }
        }

        return closest_sum;
    }
};