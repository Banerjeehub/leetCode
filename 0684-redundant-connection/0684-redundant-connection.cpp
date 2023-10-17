class Union
{
public:
    vector<int>rank;
    vector<int>parent;

    Union(int size)
    {
        rank.resize(size, 1);
        parent.resize(size);
        for(int i=0; i<size; i++)
        {
            parent[i] = i;
        }
    }

    int findUParent(int u)
    {
        if(parent[u] == u) return u;
        return parent[u] = findUParent(parent[u]);
    }

    void unionByRank(int u, int v, vector<int>&ans)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);
        if(pu == pv)
        {
            ans = {u, v};
            return;
        }

        else if(rank[pu] > rank[pv])
        {
            parent[pu] = pv;
            rank[pu]++;
        }
        else if(rank[pv] > rank[pu])
        {
            parent[pv] = pu;
            rank[pv]++;
        }
        else
        {
            parent[pu] = pv;
            rank[pu]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        int size = edges.size();
        Union ds(size+1);
        for(auto edge : edges)
        {
            ds.unionByRank(edge[0], edge[1], ans);
        }

        return ans;

    }
};