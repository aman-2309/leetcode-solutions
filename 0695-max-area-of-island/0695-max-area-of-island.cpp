class DSU {
    vector<int> parent, sz;

public:
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++)
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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DSU dsu(m*n);
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(j>0 and grid[i][j-1]==1){
                        dsu.Union(i*n+j,i*n+j-1);
                    }
                    if(i>0 and grid[i-1][j]==1){
                        dsu.Union(i*n+j,(i-1)*n+j);
                    }
                    ans = max(ans,dsu.getSize(i*n+j));
                }
                
            }
        }
        return ans;
    }
};