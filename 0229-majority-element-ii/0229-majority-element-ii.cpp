class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        set<int>st;
        int ansCnt = nums.size()/3;
    
        for(int i=0; i<nums.size(); i++)
        {   int count = 0;
            auto val = st.find(nums[i]);
            if(val != st.end()) continue;
            for(int j=0; j<nums.size(); j++)
            {
                if(nums[i] == nums[j])
                {
                    count++;
                }
            }

            if(count > ansCnt) st.insert(nums[i]);
        }

        for(auto it : st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};