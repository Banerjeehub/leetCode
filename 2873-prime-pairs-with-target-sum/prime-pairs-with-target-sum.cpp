class Solution {
public:
    void getPrimes(vector<bool>&v, int n)
    {
        v[0] = false;
        v[1] = false;

        for(int i=2; i*i <=n; i++)
        {
            if(v[i])
            {
                for(int j=i*i; j<=n; j+=i)
                {
                    v[j] = false;
                }
            }
        }
    }
    vector<vector<int>> findPrimePairs(int n) {
        
        vector<bool>prime(n+1, true);
        getPrimes(prime, n);
        map<int, int>mpp;
        set<int>st;
        vector<vector<int>>ans;
        for(int i=0; i<n+1; i++)
        {
            if(prime[i]) st.insert(i);
        }

        for(auto it : st)
        {
            int val = n - it;
            if(mpp.find(val) != mpp.end()) continue;
            if(st.find(val) != st.end()) mpp[it] = val;
        }

        for(auto it : mpp)
        {
            ans.push_back({it.first, it.second});
        }

        return ans;

    }
};