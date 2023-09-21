class DisJointSet
{
public:
    std :: vector<int>parent, rank;

    DisJointSet(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1, 0);

        for(int i=0; i<=n; i++) parent[i] = i;
    }

    int findUParent(int node)
    {
        if(node == parent[node]) return node;
        else return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if(pu == pv) return;

        else if(rank[pu] < rank[pv]) parent[pv] = pu;

        else if(rank[pv] < rank[pu]) parent[pu] = pv;

        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        DisJointSet ds(n);
        int extraConnection = 0;

        for(auto connection : connections)
        {
            int u = connection[0];
            int v = connection[1];

            if(ds.findUParent(u) == ds.findUParent(v)) extraConnection++;
            else ds.unionByRank(u, v);
        }

        int mainComopnent = 0;
        for(int i=0; i<n; i++)
        {
            if(ds.parent[i] == i)mainComopnent++;
        }

        int ans = mainComopnent - 1;

        if(extraConnection >= ans) return ans;
        else return -1;
    }
};