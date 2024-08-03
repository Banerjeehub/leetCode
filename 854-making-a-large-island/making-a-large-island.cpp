class DisJointSet {
private:
public:
    vector<int> size, parent;
    DisJointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int u) {
        if (parent[u] == u) {
            return parent[u];
        }
        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int ult_u = findParent(u);
        int ult_v = findParent(v);

        if (ult_u == ult_v)
            return;
        else if (size[ult_u] > size[ult_v]) {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        } else {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        DisJointSet ds(n * m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int dr[] = {0, 0, 1, -1};
                    int dc[] = {1, -1, 0, 0};

                    for (int idx = 0; idx < 4; idx++) {
                        int nr = i + dr[idx];
                        int nc = j + dc[idx];

                        if (nc >= 0 && nc < m && nr >= 0 && nr < n &&
                            grid[nr][nc] == 1) {
                            int node = i * m + j;
                            int adjNode = nr * m + nc;

                            ds.unionBySize(node, adjNode);
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    int dr[] = {0, 0, 1, -1};
                    int dc[] = {1, -1, 0, 0};
                    set<int> parents;
                    for (int idx = 0; idx < 4; idx++) {
                        int nr = i + dr[idx];
                        int nc = j + dc[idx];

                        if (nc >= 0 && nc < m && nr >= 0 && nr < n &&
                            grid[nr][nc] == 1) {
                            int adjNode = nr * m + nc;
                            parents.insert(ds.findParent(adjNode));
                        }
                    }

                    int temp = 1;
                    for (auto it : parents) {
                        temp += ds.size[it];
                    }

                    ans = max(ans, temp);
                }
            }
        }

        for (int i = 0; i < n * m; i++) {
            ans = max(ans, ds.size[ds.findParent(i)]);
        }

        return ans;
    }
};