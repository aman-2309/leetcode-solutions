class Solution {
public:
    void f(vector<vector<int>>& ans, vector<vector<int>>& graph, int num,
           vector<int> v) {
        if (num==graph.size()-1) {
            v.push_back(num);
            ans.push_back(v);
            return;
        } else {
            v.push_back(num);
            for (int i = 0; i < graph[num].size(); i++) {
                f(ans, graph, graph[num][i], v);

            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> v = {};
        int num = 0;
        f(ans, graph, num, v);
        return ans;
    }
};