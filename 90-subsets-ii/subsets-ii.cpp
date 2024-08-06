class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        set<vector<int>>subs;
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<pow(2, nums.size()); i++)
        {
            vector<int>temp;

            for(int j=0; j<nums.size(); j++)
            {
                if(i & (1 << j)) temp.push_back(nums[j]);
            }
            subs.insert(temp);
        }

        for(auto it : subs)
        {
            ans.push_back(it);
        }

        return ans;

    }
};