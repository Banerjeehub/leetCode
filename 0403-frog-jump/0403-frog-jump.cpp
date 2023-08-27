class Solution {
public:
    bool canCross(vector<int>& stones) {
        
        map<int, unordered_set<int>>mp;

        mp[1] = {1};

        for(int i=1; i<stones.size(); i++)
        {
            for(auto jumps : mp[stones[i]])
            {
                mp[stones[i]+ jumps].insert(jumps);
                mp[stones[i] + jumps+1].insert(jumps+1);
                mp[stones[i] + jumps-1].insert(jumps-1);
            }
            
        }
        return mp[stones.back()].size() != 0;
    }
};