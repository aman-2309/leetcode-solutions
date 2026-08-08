class DSU {
    vector<int> parent, sz;

public:
    DSU(int n) {
        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        for (int i = 0; i <= n; i++)
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
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        DSU dsu(n);
        for(int i=0;i<n;i++){
            if(graph[i].size()){
                int first = graph[i][0];
                for(int j=0;j<graph[i].size();j++){
                    if(dsu.find(i)==dsu.find(graph[i][j])) return false;
                    dsu.Union(first,graph[i][j]);
                }
            }
        }
        return true;
    }
};

