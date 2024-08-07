class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //if(nums.size() == 1) return 
        vector<vector<int>>ans;
         if (nums.size() < 4) return ans; 
        set<vector<int>>st;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-3; i++)
        {
            for(int j=i+1; j<nums.size()-2; j++)
            {
                int k = j+1;
                int l = nums.size()-1;

                while(k < l)
                {
                    long long currSum = static_cast<long long>(nums[i]) + static_cast<long long>(nums[j]) + static_cast<long long>(nums[k]) + static_cast<long long>(nums[l]);
                    if(currSum == target)
                    {
                        st.insert({nums[i] , nums[j] , nums[k] ,nums[l]});
                        k++;
                        l--;
                    }
                    else if(currSum > target) l--;
                    else k++;
                }
            }
        }

        for(auto it : st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};