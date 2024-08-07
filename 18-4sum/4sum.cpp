class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int size = nums.size();

        set<vector<int>>st;
        vector<vector<int>>output;

        for(int i=0;i<size-3;i++)
        {
            for(int j=i+1;j<size-2; j++)
            {
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j+1;
                int high = size-1;
                
                while(low < high)
                {
                    if(nums[low]+nums[high] < newTarget)
                    {
                        low++;
                    }
                    else if(nums[low]+nums[high] > newTarget)
                    {
                        high--;
                    }
                    else
                    {
                        st.insert({nums[i],nums[j],nums[low],nums[high]});
                        low++;
                        high--;
                    }
                } 
            }
        }
        for(auto i:st)
        {
            output.push_back(i);
        }

        return output;
    }
};