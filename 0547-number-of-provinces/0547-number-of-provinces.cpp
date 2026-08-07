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
            sz[b] = 0;
        } else {
            parent[a] = b;
            sz[b] += sz[a];
            sz[a] = 0;
        }
    }

    bool isConnected(int a, int b) { return find(a) == find(b); }

    int getSize(int x) { return sz[find(x)]; }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        DSU dsu(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isConnected[i][j]==1){
                    dsu.Union(i,j);
                }
            }
        }
        int ans = 0;

        for(int i=0;i<n;i++){
            if(dsu.find(i)==i) ans++;
        }

        return ans;
    }
};