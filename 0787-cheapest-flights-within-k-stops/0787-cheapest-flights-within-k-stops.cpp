class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto& e : flights) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            graph[u].push_back({w, v});
        }

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<>>
            pq;

        vector<vector<int>> minWt(n, vector<int>(k + 2, INT_MAX));

        minWt[src][0] = 0;
        pq.push({0, src, 0});

        while (!pq.empty()) {

            auto [wt, u, ed] = pq.top();
            pq.pop();

            for (auto [w, v] : graph[u]) {

                int newWt = wt + w;
                int newEd = ed + 1;

                if (newEd > k + 1)
                    continue;

                if (newWt < minWt[v][newEd]) {
                    minWt[v][newEd] = newWt;
                    pq.push({newWt, v, newEd});
                }
            }
        }
        int ans = INT_MAX;
        for(auto &ele:minWt[dst]){
            ans = min(ans,ele);
        }

        return ans==INT_MAX? -1:ans;
    }
};