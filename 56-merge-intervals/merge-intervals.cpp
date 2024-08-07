class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end());
        for(auto it : intervals)
        {
            int start = it[0];
            int end = it[1];
            if(ans.empty() || ans.back()[1] < start)
            {
                ans.push_back(it);

            }
            else
            {
                auto back = ans.back();
                int b_start = back[0];
                int b_end = back[1];
                if(b_end >= start)
                {
                   ans.pop_back();
                   if(b_end > end) end = b_end;
                   ans.push_back({b_start, end});
                }
            }
        }

        return ans;
    }
};