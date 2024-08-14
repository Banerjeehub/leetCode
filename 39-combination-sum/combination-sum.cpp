class Solution {
public:
    void helper(int idx, vector<int>& can, int target, vector<int>& temp,vector<vector<int>>&ans)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(target < 0) return;
        for(int i=idx; i<can.size(); i++)
        {
            temp.push_back(can[i]);
            helper(i, can, target-can[i], temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& can, int target) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        helper(0, can, target, temp, ans);
        return ans;
    }
};