class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        for(int i=0; i<nums.size(); i++){
            int restOfTheValue = (target - nums[i]);
            cout << restOfTheValue << endl;
            if(mp.find(restOfTheValue) != mp.end())
            {
                cout << i << " " << mp[restOfTheValue];
                return {i, mp[restOfTheValue]};
            }

            mp[nums[i]] = i;
        }
        
        return {};
    }
};