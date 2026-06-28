class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);

        for (auto& e : times) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            graph[u].push_back({w, v});
            // graph[v].push_back({w, u});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<bool> vis(n+1, false);
        vector<int> minWt(n+1, INT_MAX);

        minWt[0] = -1;
        minWt[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {

            auto [wt, u] = pq.top();
            pq.pop();

            if (vis[u])
                continue;

            vis[u] = true;

            for (auto [w, v] : graph[u]) {

                if (!vis[v] && w + wt < minWt[v]) {

                    minWt[v] = w + wt;
                    pq.push({w + wt, v});
                }
            }
        }

        int ans = -1;
        for(int &ele:minWt){
            if(ele==INT_MAX){
                return -1;
            }else{
                ans = max(ans,ele);
            }
        }

        return ans;
    }
};