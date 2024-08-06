class Solution {
public:
    vector<vector<int>> ans;
    void fun(vector<int>& v, int k, int sum, int i){
        if(sum==0 && k==0){
            ans.push_back(v);
            return;
        }
        if(i>9 || sum<0 || k<0){
            return ;
        }
        if(sum-i>=0){
            fun(v,k,sum,i+1);
            v.push_back(i);
            fun(v,k-1,sum-i,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n>55)
            return ans;
        vector<int> v;
        fun(v,k,n,1);
        return ans;
    }
};