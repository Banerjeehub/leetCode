class Solution {
private:
    void getCombinations(int idx, int liberty, int target, vector<vector<int>>&ans, vector<int>temp)
    {
        if(liberty == 0 && target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(liberty < 0 || target < 0 || idx > 9) return;

        if(target >= idx) // target - idx >= 0
        {
            getCombinations(idx+1, liberty, target, ans, temp);
            temp.push_back(idx);
            getCombinations(idx+1, liberty-1, target - idx, ans, temp);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<vector<int>>ans;
        vector<int>temp;

        getCombinations(1, k, n, ans, temp);

        return ans;
    }
};