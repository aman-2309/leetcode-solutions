class Solution {
public:
    int ans = 0;
    void func(int x, int n, vector<bool>& vis,
              vector<list<int>>& mp) {
        if (x > n) {
            ans++;
            return;
        }

        for (auto ele : mp[x]) {
            if (!vis[ele]) {
                vis[ele] = true;
                func(x + 1, n, vis, mp);
                vis[ele] = false;
            }
        }
    }
    int countArrangement(int n) {
        vector<bool> vis(n + 1, false);
        vector<list<int>> mp(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (i % j == 0 or j % i == 0) {
                    mp[i].push_back(j);
                    if (i != j)
                        mp[j].push_back(i);
                }
            }
        }
        func(1, n, vis, mp);

        return ans;
    }
};