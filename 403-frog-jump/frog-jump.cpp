class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;
        unordered_map<int, unordered_set<int>>mpp;

        mpp[1] = {1};

        for(int i=1; i<stones.size(); i++)
        {
            for(auto jump : mpp[stones[i]])
            {
                mpp[stones[i] + jump].insert(jump);
                mpp[stones[i] + jump+1].insert(jump+1);
                mpp[stones[i] + jump-1].insert(jump-1);
            }
        }

        return mpp[stones.back()].size() != 0;

    }
};