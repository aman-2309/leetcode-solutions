class Solution {
public:
    double dfs(string src, string dest, unordered_set<string>& vis,
              unordered_map<string, vector<pair<string, double>>> & graph) {
        if (src == dest)
            return 1.0;

        vis.insert(src);

        for (auto& nbr : graph[src]) {
            if (vis.count(nbr.first))
                continue;

            double res = dfs(nbr.first, dest, vis, graph);
            if (res != -1.0) {
                return res * nbr.second;
            }
        }

        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < n; i++) {
            string a = equations[i][0];
            string b = equations[i][1];

            graph[a].push_back({b, values[i]});
            graph[b].push_back({a, 1.0 / values[i]});
        }
        int l = queries.size();
        vector<double> ans;
        for (int i = 0; i < l; i++) {
            string a = queries[i][0];
            string b = queries[i][1];

            if (graph.find(a) == graph.end() || graph.find(b) == graph.end()) {
                ans.push_back(-1.00000);
                continue;
            }
            unordered_set<string> vis;
            ans.push_back(dfs(a,b,vis,graph));
            
        }
        return ans;
    }
};