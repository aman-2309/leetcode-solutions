class DSU {
    vector<int> parent, sz;

public:
    DSU(int m, int n, vector<vector<char>>& grid) {
        parent.resize(m * n);
        sz.resize(m * n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int id = i * n + j;
                parent[id] = id;
                sz[id] = grid[i][j] - '0';
            }
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (sz[a] >= sz[b]) {
            parent[b] = a;
            sz[a] += sz[b];
        } else {
            parent[a] = b;
            sz[b] += sz[a];
        }
    }

    bool isConnected(int a, int b) { return find(a) == find(b); }

    int getSize(int x) { return sz[find(x)]; }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DSU dsu(m, n, grid);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    if (j > 0 and grid[i][j - 1] == '1') {
                        dsu.Union(i * n + j, i * n + j - 1);
                    }
                    if (i > 0 and grid[i - 1][j] == '1') {
                        dsu.Union(i * n + j, (i - 1) * n + j);
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dsu.getSize(i * n + j)>0 and dsu.find(i * n + j) == i * n + j)
                    ans++;
            }
        }

        return ans;
    }
};