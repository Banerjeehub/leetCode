class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>temp(arr);
        sort(temp.begin(), temp.end());
        int rank = 1;
        map<int, int>mpp;

        for(auto it : temp)
        {
            if(mpp.find(it) == mpp.end()) mpp[it] = rank++;
        }

        vector<int>ans;
        for(auto it: arr)
        {
            ans.push_back(mpp[it]);
        }

        return ans;
    }
};