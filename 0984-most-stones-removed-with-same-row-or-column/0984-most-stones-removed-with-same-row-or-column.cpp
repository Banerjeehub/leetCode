class DisjointSet
{
public:
    std :: vector<int> parent, rank, size;

    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i; 
            size[i] = 1;
        }    
    }
    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        else
            return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv)
            return;

        else if (rank[pu] < rank[pv])
            parent[pv] = pu;

        else if (rank[pv] < rank[pu])
            parent[pu] = pv;

        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);

        if (pu == pv)
            return;

        else if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int mxRow = 0, mxCol = 0;

        for(auto it : stones)
        {
            mxRow = max(mxRow, it[0]);
            mxCol = max(mxCol, it[1]); 
        }
        DisjointSet ds(mxRow+mxCol+1);
        unordered_map<int, int>mpp;
        for(auto it : stones)
        {
            int row = it[0];
            int col = mxRow + it[1] + 1;
            ds.unionBySize(row, col);
            mpp[row] = 1;
            mpp[col] = 1;
        }
        int count = 0;
        for(auto it : mpp)
        {
            if(ds.findUParent(it.first) == it.first) count++;
        }

        return n - count;

    }
};