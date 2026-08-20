class DSU {
    vector<int> parent, sz;

public:
    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 0; i < n + 1; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b) {
        a = find(a);
        b = find(b);
        if (sz[a] >= sz[b]) {
            parent[b] = a;
            sz[a] += sz[b];
        } else {
            parent[a] = b;
            sz[b] += sz[a];
        }
    }

    int getSize(int a) { return sz[a]; }

    bool isConnected(int a, int b) { return find(a) == find(b); }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for (auto& v : edges) {
            if (dsu.isConnected(v[0], v[1]))
                return {v[0], v[1]};
            else
                dsu.Union(v[0], v[1]);
        }
        return {};
    }
};