class Solution {
public:
    void topoBFS(vector<list<int>>& graph,vector<int> &ans) {
        int v = graph.size();
        int total = 0;
        vector<int> indegree(v, 0);
        for (int i = 0; i < v; i++) {
            for (auto ng : graph[i]) {
                indegree[ng]++;
            }
        }
        queue<int> qu;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0) {
                qu.push(i);
            }
        }

        while (qu.size()) {
            int node = qu.front();
            ans.push_back(node);
            qu.pop();
            for (auto ng : graph[node]) {

                indegree[ng]--;
                if (indegree[ng] == 0) {
                    qu.push(ng);
                }
            }
        }
    }
    void add_edge(int src, int dest, vector<list<int>>& graph,bool bi_dir = true) {
        graph[src].push_back(dest);
        if (bi_dir) {
            graph[dest].push_back(src);
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int v = numCourses;
        vector<int> ans;
        vector<list<int>> graph(v,list<int>());
        for (auto& vec : pre) {
            add_edge(vec[1], vec[0],graph, false);
        }
        topoBFS(graph,ans);
        return ans.size()==v? ans : vector<int>{};
    }
};